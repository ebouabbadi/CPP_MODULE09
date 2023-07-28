#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <deque>
#include <iostream>

class PmergeMe
{
private:
    std::list<int> _List;

public:
    PmergeMe(char **av, int ac);
    void readPositiveInteger(char **av, int ac);
    void    print_List();
    ~PmergeMe();
    std::list<int>  get_List();
};

#endif