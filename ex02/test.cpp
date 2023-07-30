#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include <chrono> // For measuring time

// Function to merge two sorted lists
void merge(std::list<int> &arr, std::list<int> &leftArr, std::list<int> &rightArr)
{
    std::list<int>::iterator leftIt = leftArr.begin();
    std::list<int>::iterator rightIt = rightArr.begin();

    while (leftIt != leftArr.end() && rightIt != rightArr.end())
    {
        if (*leftIt <= *rightIt)
        {
            arr.push_back(*leftIt);
            ++leftIt;
        }
        else
        {
            arr.push_back(*rightIt);
            ++rightIt;
        }
    }

    while (leftIt != leftArr.end())
    {
        arr.push_back(*leftIt);
        ++leftIt;
    }

    while (rightIt != rightArr.end())
    {
        arr.push_back(*rightIt);
        ++rightIt;
    }
}

// Merge-insert sort algorithm
void mergeInsertSort(std::list<int> &arr)
{
    if (arr.size() <= 1)
        return;

    std::list<int> leftArr, rightArr;
    std::list<int>::iterator it = arr.begin();

    for (int i = 0; i < arr.size() / 2; ++i)
    {
        leftArr.push_back(*it);
        ++it;
    }

    for (; it != arr.end(); ++it)
    {
        rightArr.push_back(*it);
    }

    mergeInsertSort(leftArr);
    mergeInsertSort(rightArr);

    arr.clear();
    merge(arr, leftArr, rightArr);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <positive integers separated by spaces>\n";
        return 1;
    }

    std::list<int> sequence;

    // Read the positive integer sequence from the command line arguments
    for (int i = 1; i < argc; ++i)
    {
        int num = std::atoi(argv[i]);
        if (num < 0)
        {
            std::cerr << "Error: Only positive integers are allowed.\n";
            return 1;
        }
        sequence.push_back(num);
    }

    // Display unsorted sequence
    std::cout << "Unsorted sequence: ";
    for (std::list<int>::iterator it = sequence.begin(); it != sequence.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
 
    // Sort the sequence using merge-insert sort
    std::clock_t start1 = std::clock();
    mergeInsertSort(sequence);
    std::clock_t end1 = std::clock();

    // Display sorted sequence
    std::cout << "Sorted sequence: ";
    for (std::list<int>::iterator it = sequence.begin(); it != sequence.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // Display the time taken by the algorithm (first container)
    double duration1 = (end1 - start1) / (double)CLOCKS_PER_SEC;
    std::cout << "Time taken by the algorithm (first container): " << duration1 << " seconds\n";

    // Sort a copy of the original sequence to measure time for the second container
    std::list<int> sequence_copy = sequence;
    std::clock_t start2 = std::clock();
    mergeInsertSort(sequence_copy);
    std::clock_t end2 = std::clock();

    // Display the time taken by the algorithm (second container)
    double duration2 = (end2 - start2) / (double)CLOCKS_PER_SEC;
    std::cout << "Time taken by the algorithm (second container): " << duration2 << " seconds\n";

    return 0;
}
