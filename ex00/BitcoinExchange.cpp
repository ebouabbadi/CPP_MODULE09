#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(char *av)
{
    (void)av;


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

