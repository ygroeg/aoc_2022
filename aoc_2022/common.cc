#include "common.h"

#include <fstream>
#include <iostream>

namespace aoc_2022 {

std::vector<std::string> ReadFile(const std::string &path) {
  std::vector<std::string> res;
  std::ifstream infile(path);
  std::string line;
  while (std::getline(infile, line)) {
    //    std::cout << line << '\n';
    res.push_back(line);
  }
  infile.close();
  return res;
}

}  // namespace aoc_2022
