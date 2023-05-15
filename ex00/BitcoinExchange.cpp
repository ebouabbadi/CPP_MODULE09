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
        std::string line ;
        while(std::getline(file, line))
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
