#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
        {
            throw "Error: could not open file.";
        }
        BitcoinExchange bitcoinEx(av[1]);
    }
    catch (char const *str)
    {
        std::cerr <<str<< '\n';
    }

    return (0);
}