#include <iostream>
#include <fstream>
#include <string>

int main() {
  std::ifstream file("data.csv");
  if (!file.is_open()) {
    std::cerr << "Error: could not open file.\n";
    return 1;
  }

  std::string file_contents;
  std::string line;
  while (std::getline(file, line)) {
    file_contents += line;
    file_contents += "\n";
  }

  file.close();

  std::cout << "File contents:\n" << file_contents << "\n";

  return 0;
}
