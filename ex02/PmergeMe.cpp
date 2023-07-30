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
        if (n <= 0)
            throw "Error.";
        this->_List.push_back(n);
    }
}

void mergeIS(std::list<int> &listArr)
{
    if (listArr.size() <= 1)
        return;
    std::list<int> l_List, r_List;
    std::list<int>::iterator it = listArr.begin();
    for (int i = 0; i < listArr.size() / 2; i++)
    {
        l_List.push_back(*it);
        it++;
    }
    for (; it != listArr.end(); it++)
        r_List.push_back(*it);
    mergeIS(l_List);
    mergeIS(r_List);
    listArr.clear();
    std::list<int>::iterator lIt = l_List.begin();
    std::list<int>::iterator rIt = r_List.begin();
    while (lIt != l_List.end() && rIt != r_List.end())
    {
        if (*lIt <= *rIt)
        {
            listArr.push_back(*lIt);
            lIt++;
        }
        else
        {
            listArr.push_back(*rIt);
            rIt++;
        }
    }
    while (lIt != l_List.end())
    {
        listArr.push_back(*lIt);
        lIt++;
    }
    while (rIt != r_List.end())
    {
        listArr.push_back(*rIt);
        rIt++;
    }
}

void PmergeMe::work_List()
{
    mergeIS(this->_List);
    std::cout<<"after: ";
    print_List();
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