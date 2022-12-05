#pragma once

#include <string>
#include <vector>

namespace aoc_2022 {
namespace day_1 {

void Solution(const std::string& path);

}
namespace day_2 {

enum class Outcomes {
  kLoss = 0,
  kDraw = 3,
  kWin = 6,
};

enum class Choices {
  kRock = 1,
  kPaper = 2,
  kScissors = 3,
};

const std::vector<Choices> wins = {
    {Choices::kScissors},
    {Choices::kRock},
    {Choices::kPaper},
};
const std::vector<Choices> losses = {
    {Choices::kPaper},
    {Choices::kScissors},
    {Choices::kRock},
};

Choices Letter2Choices(const char);

Outcomes Letter2Outcomes(const char);

Outcomes Winner(const Choices& p1, const Choices& p2);

int CalculateStrat1(const Choices& p1, const Choices& p2);

int CalculateStrat2(const Choices& p1, const Outcomes& out);

void Solution(const std::string& path);

// int Calculate
}  // namespace day_2
namespace day_3 {
void Solution(const std::string& path);
void Part1(const std::string& path);
void Part2(const std::string& path);
}  // namespace day_3
namespace day_4 {
void Solution(const std::string& path);
void Part1(const std::string& path);
void Part2(const std::string& path);
}  // namespace day_4
namespace day_5 {
void Solution(const std::string& path);
void Part1(const std::string& path);
void Part2(const std::string& path);
}  // namespace day_5
}  // namespace aoc_2022
