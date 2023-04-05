#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout<<"Error: could not open file."<<std::endl;
        return (0);
    }
    BitcoinExchange bitcoinEx(av[1]);
    std::cout<< bitcoinEx.getBuffer();
    return (0);
}