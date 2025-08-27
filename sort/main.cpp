#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main(int argc, char* argv[]) {
  if (argc == 2) {
    std::ifstream input{argv[1]};

    if (!input) {
      std::cerr << argv[1] << " couldn't be opened";
      return 1;
    }

    std::string line{};
    std::vector<std::string> lines{};
    while (std::getline(input, line)) {
      lines.push_back(line);
    }

    std::sort(lines.begin(), lines.end(),
              [](const std::string& a, const std::string& b) {
                return std::lexicographical_compare(
                    a.begin(), a.end(), b.begin(), b.end(),
                    [](char char_a, char char_b) {
                      return std::tolower(char_a) < std::tolower(char_b);
                    });
              });

    for (auto& l : lines) {
      std::cout << l << std::endl;
    }

    return 0;
  }

  std::cout << "Usage: sort <filename>";
  return 0;
}
