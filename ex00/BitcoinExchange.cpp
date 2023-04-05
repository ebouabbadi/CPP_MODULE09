#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(char *av)
{
    std::string file_name = (std::string)av;
    std::ifstream file(file_name);
    std::stringstream buffer;
    buffer << file.rdbuf();
    this->_buffer= buffer.str();
    file.close();
}

std::string BitcoinExchange::getBuffer()
{
    return (this->_buffer);
}

BitcoinExchange::~BitcoinExchange()
{
}