#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

std::string BitcoinExchange::openAndReadFile(std::string nameFile)
{
    std::ifstream file(nameFile);
    std::string buffer;
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            buffer += line;
            buffer += '\n';
        }
        file.close();
    }
    else
        throw "Error: could not open file.";
    return (buffer);
}

BitcoinExchange::BitcoinExchange(char *av)
{
    this->_bufferInput = openAndReadFile((std::string)av);
    this->_bufferData = openAndReadFile("data.csv");
    this->shippingData();
    this->split_input();
    if (this->_Input[0] != "date | value")
        throw "Error: bad input => first line not good";
    for (size_t i = 1; i < _Input.size(); i++)
    {
        int token = this->parsingInput(this->_Input[i]);
        if (token == BADINPUT)
            std::cout << "Error: bad input => " << this->_Input[i] << std::endl;
        else if (token == NOTPOSITIVE)
            std::cout << "Error: not a positive number." << std::endl;
        else if (token == LARGENUMBER)
            std::cout << "Error: too large a number." << std::endl;
    }
}

void BitcoinExchange::shippingData()
{
    size_t i = 0;
    while (this->_bufferData[i] != '\n')
        i++;
    for (i++; i < this->_bufferData.size(); i++)
    {
        std::string date;
        for (; this->_bufferData[i] != ','; i++)
            date.push_back(this->_bufferData[i]);
        std::string value;
        for (i++; this->_bufferData[i] != '\n'; i++)
            value.push_back(this->_bufferData[i]);
        this->_Data.insert(std::make_pair(date, std::stod(value)));
    }
}

void BitcoinExchange::split_input()
{
    int i = 0, count = 0;
    while (i < (int)this->_bufferInput.size())
    {
        int index = this->_bufferInput.find("\n", i);
        if ((size_t)index == std::string::npos)
            break;
        else
        {
            std::string str;
            for (; i < index; i++)
                str.push_back(this->_bufferInput[i]);
            this->_Input.insert(std::make_pair(count++, str));
        }
        i++;
    }
}

bool stringDigit(std::string str)
{
    size_t i = 0;
    if (str[0] == '+' || str[0] == '-')
        i++;
    for (; i < str.size(); i++)
    {
        if (!isdigit(str[i]))
            return (false);
    }
    return (true);
}

bool stringDigitOrDouble(std::string str)
{
    size_t i = 0;
    int count = 0;
    if (str.size() == 1 && !isdigit(str[0]))
        return (false);
    if (str[0] == '+' || str[0] == '-')
        i++;
    for (; i < str.size(); i++)
    {
        if (str[i] == '.')
            count++;
        else if (!isdigit(str[i]))
            return (false);
    }
    if (count > 1 || str[0] == '.' || ((str[0] == '+' || str[0] == '-') && str[1] == '.'))
        return (false);
    return (true);
}

bool checkDate(int y, int m, int d)
{
    if (m == 4 || m == 6 || m == 9 || m == 11)
    {
        if (d > 30 || d < 1)
            return (false);
    }
    else if (m == 2)
    {
        if (y % 4)
        {
            if (d > 28 || d < 1)
                return (false);
        }
        else
        {
            if (d > 29 || d < 1)
                return (false);
        }
    }
    else if ((m <= 12 && m >= 1))
    {
        if (d > 31 || d < 1)
            return (false);
    }
    else
        return (false);
    return (true);
}

int checkInput(int y, int m, int d, double v)
{
    if (y < 2023 && y >= 2009)
    {
        if (y == 2022 && m > 3)
            return (BADINPUT);
        if (y == 2022 && m == 3 && d > 29)
            return (BADINPUT);
        if (checkDate(y, m, d) == false)
            return (BADINPUT);
        if (v < 0)
            return (NOTPOSITIVE);
        if (v > 1000)
            return (LARGENUMBER);
    }
    else
        return (BADINPUT);
    return (VALID);
}

std::string createDate(int years, int month, int day)
{
    std::string date;
    date.append(std::to_string(years));
    date.append("-");
    if (month < 10)
        date.append("0");
    date.append(std::to_string(month));
    date.append("-");
    if (day < 10)
        date.append("0");
    date.append(std::to_string(day));
    return (date);
}

int BitcoinExchange::exchangeRate(int years, int month, int day, double value)
{
    std::string date = createDate(years, month, day);
    while (true)
    {
        std::map<std::string, double>::iterator it = this->_Data.begin();
        std::map<std::string, double>::iterator itEnd = this->_Data.end();
        for (; it != itEnd; it++)
        {
            if (!it->first.compare(createDate(years, month, day)))
            {
                std::cout << date << " => " << value << " = " << it->second * value << std::endl;
                return (VALID);
            }
        }
        if (day < 31)
            day++;
        else
        {
            if (month < 12)
            {
                month++;
                day = 1;
            }
            else
            {
                years++;
                month = 1;
                day = 1;
            }
        }
    }
    return (VALID);
}

int BitcoinExchange::parsingInput(std::string str)
{
    int years, month, day;
    double value;
    if (str[4] != '-' || str[7] != '-' || str.substr(10, 3).compare(" | "))
        return (BADINPUT);
    if (!stringDigit(str.substr(0, 4)) || !stringDigit(str.substr(5, 2)) || !stringDigit(str.substr(8, 2)) || !stringDigitOrDouble(str.substr(13, str.length() - 13)))
        return (BADINPUT);
    years = std::stoi(str.substr(0, 4));
    month = std::stoi(str.substr(5, 2));
    day = std::stoi(str.substr(8, 2));
    value = std::stod(str.substr(13, str.length() - 13));
    int token = checkInput(years, month, day, value);
    if (token != VALID)
        return (token);
    return (exchangeRate(years, month, day, value));
}

std::map<std::string, double> BitcoinExchange::getData()
{
    return (this->_Data);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    this->_Input = copy._Input;
    this->_Data = copy._Data;
    this->_bufferData = copy._bufferData;
    this->_bufferInput = copy._bufferInput;
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}
