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
    (void)av;
    this->_bufferData = openAndReadFile((std::string)av);
    this->_bufferInput = openAndReadFile("input.txt");
    this->shippingData();
    this->shippingInput();
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

void BitcoinExchange::shippingInput()
{
    for (size_t i = 0; i < this->_bufferInput.size(); i++)
    {
        std::string date;
        for (; this->_bufferInput[i] != '|'; i++)
            date.push_back(this->_bufferInput[i]);
        std::string value;
        for (i++; this->_bufferInput[i] != '\n'; i++)
            value.push_back(this->_bufferInput[i]);
        this->_Input.insert(std::make_pair(date, std::stod(value)));
    }
     for (const auto& entry : this->_Input) {
        std::cout << "Key 2: " << entry.first << "---- Value: " << entry.second << std::endl;
    }
}

int BitcoinExchange::parsingInput(std::string date, std::string value)
{
    
}

std::map<std::string, double> BitcoinExchange::getData()
{
    return (this->_Data);
}

std::map<std::string, double> BitcoinExchange::getInput()
{
    return (this->_Input);
}

BitcoinExchange::~BitcoinExchange()
{
}
