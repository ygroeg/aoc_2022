#include "solutions.h"

#include <algorithm>
#include <iostream>
#include <map>

#include "common.h"

namespace aoc_2022 {

void day_1::Solution() {
  auto contents = ReadFile("../input_d1.txt");
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

void day_2::Solution() {
  auto contents = ReadFile("../input_d2.txt");
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

day_2::Choices day_2::Letter2Choices(const char input) {
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

day_2::Outcomes day_2::Letter2Outcomes(const char input) {
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

int day_2::CalculateStrat1(const Choices& p1, const Choices& p2) {
  int res = 0;
  int c1 = static_cast<int>(p1);
  res += c1;
  res += static_cast<int>(Winner(p1, p2));
  return res;
}

day_2::Outcomes day_2::Winner(const Choices& p1, const Choices& p2) {
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

int day_2::CalculateStrat2(const Choices& p1, const Outcomes& out) {
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

}  // namespace aoc_2022
