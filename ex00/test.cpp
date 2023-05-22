#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, double> container;

    while (true) {
        std::string key;
        double value;

        std::cout << "Enter a string: ";
        std::cin >> key;

        std::cout << "Enter a double value: ";
        std::cin >> value;

        // Check if the string already exists in the map
        auto it = container.find(key);
        if (it != container.end()) {
            std::cout << "String already exists in the map. Updating the value." << std::endl;
            it->second = value;  // Update the double value
        } else {
            // Insert the string and double value into the map
            container[key] = value;
        }

        char choice;
        std::cout << "Do you want to continue (y/n)? ";
        std::cin >> choice;

        if (choice != 'y' && choice != 'Y')
            break;
    }

    // Print the contents of the map
    std::cout << "Map contents:" << std::endl;
    for (const auto& entry : container) {
        std::cout << "String: " << entry.first << ", Double: " << entry.second << std::endl;
    }

    return 0;
}
