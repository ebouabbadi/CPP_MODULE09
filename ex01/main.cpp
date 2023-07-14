#include "RPN.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
        {
            throw "Error";
        }
        RPN rpn(av[1]);
    }
    catch (char const *str)
    {
        std::cerr << str << '\n';
    }
    return (0);
}