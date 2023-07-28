#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **av, int ac)
{
    this->readPositiveInteger(av, ac);
}

void PmergeMe::readPositiveInteger(char **av, int ac)
{
    for (int i = 1; i < ac; i++)
    {
        int n = std::atoi(av[i]);
        if (n < 0)
            throw "Error.";
        this->_List.push_back(n);
    }
}

void PmergeMe::print_List()
{
    for (std::list<int>::iterator it = _List.begin(); it != _List.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

std::list<int> PmergeMe::get_List()
{
    return (this->_List);
}

PmergeMe::~PmergeMe()
{
}