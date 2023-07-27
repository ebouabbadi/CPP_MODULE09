#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <deque>

class PmergeMe
{
private:
    std::list<int>   _List;
    std::deque<int> _Deque;
public:
    PmergeMe();
    ~PmergeMe();
};

#endif