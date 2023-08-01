#include "PmergeMe.hpp"
#include <chrono>

int main(int ac, char **av)
{
    std::chrono::system_clock::time_point now;
    std::chrono::system_clock::time_point end;
    std::chrono::duration<double> D;
    try
    {
        if (ac < 2)
            throw "Error.";
        PmergeMe P(av, ac);
        std::cout << "Before: ";
        P.print_List();
        now = std::chrono::system_clock::now();
        P.work_List();
        end = std::chrono::system_clock::now();
        D = std::chrono::duration_cast<std::chrono::microseconds>(end - now);
        std::cout << "Time to process a range of " << P.get_List().size() << " elements with std::list : " << D.count() << " us" << std::endl;
         now = std::chrono::system_clock::now();
        P.work_Deque();
        end = std::chrono::system_clock::now();
        D = std::chrono::duration_cast<std::chrono::microseconds>(end - now);
        std::cout << "Time to process a range of " << P.get_Deque().size() << " elements with std::deque : " << D.count() << " us" << std::endl;
    }
    catch (char const *str)
    {
        std::cerr << str << '\n';
    }
    return (0);
}