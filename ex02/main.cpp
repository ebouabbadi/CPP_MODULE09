#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac < 2)
            throw "Error.";
        PmergeMe P(av, ac);
        std::cout << "befor: ";
        P.print_List();
        P.work_List();

    }
    catch (char const *str)
    {
        std::cerr << str << '\n';
    }
    return (0);
}