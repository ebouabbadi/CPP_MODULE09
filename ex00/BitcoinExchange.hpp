#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

#define BADINPUT 10
#define NOTPOSITIVE 11
#define LARGENUMBER 12
#define VALID 13

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
    BitcoinExchange(const BitcoinExchange &copy);
    BitcoinExchange &operator=(const BitcoinExchange &copy);
    std::string openAndReadFile(std::string nameFile);
    void shippingData();
    int parsingInput(std::string str);
    void split_input();
    std::map<std::string, double> getData();
    int exchangeRate(int years, int month, int day, double);
    ~BitcoinExchange();
};

#endif