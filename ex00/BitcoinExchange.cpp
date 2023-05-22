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
        std::string line;0
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
    this->_bufferInput = openAndReadFile((std::string)av);
    // this->shippingData()
    ;
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

int BitcoinExchange::parsingInput(std::string line)
{
    
}

std::map<std::string, double> BitcoinExchange::getData()
{
    return (this->_Data);
}

BitcoinExchange::~BitcoinExchange()
{
}
