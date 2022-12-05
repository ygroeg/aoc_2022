#include "solutions.h"

#include <algorithm>
#include <iostream>
#include <map>

#include "common.h"

namespace aoc_2022 {
namespace day_1 {

void Solution(const std::string& path) {
  auto contents = ReadFile(path);
  int biggest_stack = 0;
  int stack = 0;
  std::vector<int> elfs;
  for (const std::string& s : contents) {
    if (!s.empty()) {
      stack += std::stoi(s);
    } else {
      if (stack > biggest_stack) {
        biggest_stack = stack;
      }
      elfs.push_back(stack);
      stack = 0;
    }
  }
  std::sort(elfs.begin(), elfs.end());
  std::reverse(elfs.begin(), elfs.end());
  std::cout << "top 3 elfs sum: " << elfs[0] + elfs[1] + elfs[2] << std::endl;

  std::cout << "biggest_stack = " << biggest_stack << std::endl;
}

}  // namespace day_1
namespace day_2 {

void Solution(const std::string& path) {
  auto contents = ReadFile(path);
  // part 1
  int sum = 0;
  for (const std::string& s : contents) {
    auto enemy = Letter2Choices(s[0]);
    auto me = Letter2Choices(s[2]);
    sum += CalculateStrat1(me, enemy);
  }
  std::cout << "strat1 yields = " << sum << std::endl;
  // part 2
  sum = 0;
  for (const std::string& s : contents) {
    auto enemy = Letter2Choices(s[0]);
    auto me = Letter2Outcomes(s[2]);
    sum += CalculateStrat2(enemy, me);
  }
  std::cout << "strat2 yields = " << sum << std::endl;
}

Choices Letter2Choices(const char input) {
  if (input == 'A' || input == 'X') {
    return Choices::kRock;
  }
  if (input == 'B' || input == 'Y') {
    return Choices::kPaper;
  }
  if (input == 'C' || input == 'Z') {
    return Choices::kScissors;
  }
}

Outcomes Letter2Outcomes(const char input) {
  if (input == 'X') {
    return Outcomes::kLoss;
  }
  if (input == 'Y') {
    return Outcomes::kDraw;
  }
  if (input == 'Z') {
    return Outcomes::kWin;
  }
}

int CalculateStrat1(const Choices& p1, const Choices& p2) {
  int res = 0;
  int c1 = static_cast<int>(p1);
  res += c1;
  res += static_cast<int>(Winner(p1, p2));
  return res;
}

Outcomes Winner(const Choices& p1, const Choices& p2) {
  if (p1 == p2) {
    return Outcomes::kDraw;
  }
  auto win = wins.at(static_cast<int>(p1) - 1);
  if (p2 == win) {
    return Outcomes::kWin;
  } else {
    return Outcomes::kLoss;
  }
}

int CalculateStrat2(const Choices& p1, const Outcomes& out) {
  int res = 0;
  int c1 = static_cast<int>(out);
  res += c1;
  if (out == Outcomes::kDraw) {
    res += static_cast<int>(p1);
    return res;
  }
  if (out == Outcomes::kLoss) {
    res += static_cast<int>(wins.at(static_cast<int>(p1) - 1));
  } else {
    res += static_cast<int>(losses.at(static_cast<int>(p1) - 1));
  }
  return res;
}
}  // namespace day_2
namespace day_3 {

void Solution(const std::string& path) {
  //  Part1(path);
  Part2(path);
}
void Part1(const std::string& path) {
  auto contents = ReadFile(path);
  int sum = 0;
  for (const std::string& s : contents) {
    auto p1 = s.substr(0, s.length() / 2);
    auto p2 = s.substr(s.length() / 2);
    auto it = find_first_of(p1.begin(), p1.end(), p2.begin(), p2.end());

    if (it != p1.end()) {
      //      std::cout << "The first match is: " << (int)*it << '\n';
      std::cout << *it << std::endl;
      if ((int)*it < 91) {  // A-Z
                            //        std::cout << (int)*it - 38 << std::endl;
        sum += (int)*it - 38;
      } else {  // a-z
                //        std::cout << (int)*it - 96 << std::endl;
        sum += (int)*it - 96;
      }
    }
    //    std::cout << s << '\t' << s.length() << '\t';
    //    std::cout << p1 << p1.length() << '\t' << p2 << p2.length() <<
    //    std::endl;
  }
  std::cout << "sum = " << sum << std::endl;
}

void Part2(const std::string& path) {
  auto contents = ReadFile(path);
  int sum = 0;
  for (auto i = 0; i < contents.size(); i += 3) {
    auto e1 = contents[i];
    auto e2 = contents[i + 1];
    auto e3 = contents[i + 2];
    std::string e1_e2;
    for (auto it = find_first_of(e1.begin(), e1.end(), e2.begin(), e2.end());
         it != e1.end();) {
      e1_e2 += *it;
      e1.erase(it);
    }
    auto it = find_first_of(e1_e2.begin(), e1_e2.end(), e3.begin(), e3.end());
    if (it != e1_e2.end()) {
      std::cout << *it << std::endl;
      if ((int)*it < 91) {  // A-Z
                            //        std::cout << (int)*it - 38 << std::endl;
        sum += (int)*it - 38;
      } else {  // a-z
                //        std::cout << (int)*it - 96 << std::endl;
        sum += (int)*it - 96;
      }
    }
  }
  std::cout << "sum = " << sum << std::endl;
}

}  // namespace day_3
namespace day_4 {
void Solution(const std::string& path) {
  //  Part1(path);
  Part2(path);
}
void Part1(const std::string& path) {
  auto contents = ReadFile(path);
  int count = 0;
  for (const std::string& s : contents) {
    auto it1 = find(s.begin(), s.end(), ',');
    std::string e1{s.begin(), it1};
    std::string e2{it1 + 1, s.end()};
    auto it2 = find(e1.begin(), e1.end(), '-');
    int n1 = std::stoi(std::string(e1.begin(), it2));
    int n2 = std::stoi(std::string(it2 + 1, e1.end()));
    auto it3 = find(e2.begin(), e2.end(), '-');
    int n3 = std::stoi(std::string(e2.begin(), it3));
    int n4 = std::stoi(std::string(it3 + 1, e2.end()));

    if (n1 <= n3 && n2 >= n4) {
      count++;
      //      std::cout << "\nfirst " << std::endl;
      //      std::cout << "biggest_stack = " << e1 << '\t' << e2 << std::endl;
      //      std::cout << "1 = " << n1 << '\t' << n3 << std::endl;
      //      std::cout << "2 = " << n2 << '\t' << n4 << std::endl;
    } else if (n3 <= n1 && n4 >= n2) {
      count++;
      //      std::cout << "\nsec " << std::endl;
      //      std::cout << "biggest_stack = " << e1 << '\t' << e2 << std::endl;
      //      std::cout << "1 = " << n1 << '\t' << n3 << std::endl;
      //      std::cout << "2 = " << n2 << '\t' << n4 << std::endl;
    }
  }
  std::cout << "cnt = " << count << std::endl;
}

void Part2(const std::string& path) {
  auto contents = ReadFile(path);
  int count = 0;
  for (const std::string& s : contents) {
    auto it1 = find(s.begin(), s.end(), ',');
    std::string e1{s.begin(), it1};
    std::string e2{it1 + 1, s.end()};
    auto it2 = find(e1.begin(), e1.end(), '-');
    int n1 = std::stoi(std::string(e1.begin(), it2));
    int n2 = std::stoi(std::string(it2 + 1, e1.end()));
    auto it3 = find(e2.begin(), e2.end(), '-');
    int n3 = std::stoi(std::string(e2.begin(), it3));
    int n4 = std::stoi(std::string(it3 + 1, e2.end()));

    if (n2 >= n3 && n1 <= n4) {
      count++;
      std::cout << "biggest_stack = " << e1 << '\t' << e2 << std::endl;
      std::cout << "n2 = " << n2 << " >= n3 = " << n3 << std::endl;
      std::cout << "n1 = " << n1 << " <= n4 = " << n4 << std::endl;
    }
    //    else if (n3 <= n1 && n4 >= n2) {
    //      count++;
    //      std::cout << "\nsec " << std::endl;
    //      std::cout << "biggest_stack = " << e1 << '\t' << e2 << std::endl;
    //      std::cout << "1 = " << n1 << '\t' << n3 << std::endl;
    //      std::cout << "2 = " << n2 << '\t' << n4 << std::endl;
    //    }
  }
  std::cout << "cnt = " << count << std::endl;
}

}  // namespace day_4
namespace day_5 {
void Solution(const std::string& path) {
  auto contents = ReadFile(path);
  int biggest_stack = 0;
  int stack = 0;
  std::vector<int> elfs;
  for (const std::string& s : contents) {
    if (!s.empty()) {
      stack += std::stoi(s);
    } else {
      if (stack > biggest_stack) {
        biggest_stack = stack;
      }
      elfs.push_back(stack);
      stack = 0;
    }
  }
  std::sort(elfs.begin(), elfs.end());
  std::reverse(elfs.begin(), elfs.end());
  std::cout << "top 3 elfs sum: " << elfs[0] + elfs[1] + elfs[2] << std::endl;

  std::cout << "biggest_stack = " << biggest_stack << std::endl;
}

void Part2(const std::string& path) {}

}  // namespace day_5

}  // namespace aoc_2022
