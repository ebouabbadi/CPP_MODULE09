#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>


class BitcoinExchange
{
private:
    std::map<std::string, double> _Input;
    std::map<std::string, double> _Data;
public:
    BitcoinExchange();
    BitcoinExchange(char *av);
    std::map<std::string, double> getInput();
    std::map<std::string, double> getData();
    ~BitcoinExchange();
    void returnData();
    void returnInput();
    void   acceptanceStation(std::string data, std::string input);

};

#endif