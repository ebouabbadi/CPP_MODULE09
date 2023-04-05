#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
private:
    std::string _buffer;
public:
    BitcoinExchange();
    BitcoinExchange(char *av);
    std::string getBuffer();
    ~BitcoinExchange();
};

#endif