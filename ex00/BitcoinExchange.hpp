#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange
{
private:
    std::map<int, std::string> _Input;
    std::map<std::string, double> _Data;
    std::string _bufferInput;
    std::string _bufferData;

public:
    BitcoinExchange();
    BitcoinExchange(char *av);
    std::string openAndReadFile(std::string nameFile);
    void shippingData();
    std::string parsingInput(std::string str);
    void split_input();
    std::map<std::string, double> getData();
    void exchangeRate(int years, int month, int day, double);
    ~BitcoinExchange();
};

#endif