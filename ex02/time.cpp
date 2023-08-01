#include <iostream>
#include <chrono>

int main() {
    // Get the current time point
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

    // Wait for 2 seconds using std::chrono::seconds
    for (size_t i = 0; i < 1000; i++)
        std::cout<<",";
    std::cout<<"\n";
    
    // Get the current time point again
    std::chrono::system_clock::time_point later = std::chrono::system_clock::now();

    // Calculate the duration between the two time points
    std::chrono::duration<double> elapsed_seconds = later - now;

    // Output the elapsed time in seconds
    std::cout << "Elapsed time: " << elapsed_seconds.count() << " seconds\n";

    return 0;
}
