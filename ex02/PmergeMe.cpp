#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **av, int ac)
{
    this->readPositiveInteger(av, ac);
}

bool checkNumber(std::string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (!isdigit(str[i]))
            return (false);
    }
    return (true);
}

void PmergeMe::readPositiveInteger(char **av, int ac)
{
    for (int i = 1; i < ac; i++)
    {
        if (!checkNumber((std::string)av[i]))
            throw "Error.";
        int n = std::atoi(av[i]);
        if (n < 0)
            throw "Error.";
        this->_List.push_back(n);
        this->_Deque.push_back(n);
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

void mergeIS(std::deque<int> &dequeArr)
{
    if (dequeArr.size() <= 1)
        return;
    std::deque<int> l_Deque, r_Deque;
    std::deque<int>::iterator it = dequeArr.begin();
    for (int i = 0; i < dequeArr.size() / 2; i++)
    {
        l_Deque.push_back(*it);
        it++;
    }
    for (; it != dequeArr.end(); it++)
        r_Deque.push_back(*it);
    mergeIS(l_Deque);
    mergeIS(r_Deque);
    dequeArr.clear();
    std::deque<int>::iterator lIt = l_Deque.begin();
    std::deque<int>::iterator rIt = r_Deque.begin();
    while (lIt != l_Deque.end() && rIt != r_Deque.end())
    {
        if (*lIt <= *rIt)
        {
            dequeArr.push_back(*lIt);
            lIt++;
        }
        else
        {
            dequeArr.push_back(*rIt);
            rIt++;
        }
    }
    while (lIt != l_Deque.end())
    {
        dequeArr.push_back(*lIt);
        lIt++;
    }
    while (rIt != r_Deque.end())
    {
        dequeArr.push_back(*rIt);
        rIt++;
    }
}

void PmergeMe::work_List()
{
    mergeIS(this->_List);
    std::cout << "After:  ";
    print_List();
}

void PmergeMe::work_Deque()
{
    mergeIS(this->_Deque);
    // std::cout << "After:  ";
    // print_List();
}

void PmergeMe::print_Deque()
{
    std::cout << "i'm deque\n";
    for (std::deque<int>::iterator it = _Deque.begin(); it != _Deque.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
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

std::deque<int> PmergeMe::get_Deque()
{
    return (this->_Deque);
}

PmergeMe::~PmergeMe()
{
}