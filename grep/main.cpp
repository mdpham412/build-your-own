#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
  if (argc == 3) {
    std::ifstream input{argv[2]};

    if (!input) {
      std::cerr << argv[2] << " couldn't be opened";
      return 1;
    }

    std::string line{};
    while (std::getline(input, line)) {
      if (line.find(argv[1]) != line.npos) {
        std::cout << line << std::endl;
      }
    }

    return 0;
  }

  std::cout << "Usage: grep <pattern> <filename>";
  return 0;
}
