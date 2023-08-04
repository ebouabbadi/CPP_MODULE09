#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <deque>
#include <iostream>

class PmergeMe
{
private:
    std::list<int> _List;
    std::deque<int> _Deque;

public:
    PmergeMe(char **av, int ac);
    PmergeMe(const PmergeMe &copy);
    PmergeMe    &operator=(const PmergeMe &copy);
    void readPositiveInteger(char **av, int ac);
    void    print_List();
    void    print_Deque();
    void    work_List();
    void    work_Deque();
    ~PmergeMe();
    std::list<int>  get_List();
    std::deque<int>  get_Deque();
};

#endif