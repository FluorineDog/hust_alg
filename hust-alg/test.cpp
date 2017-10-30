#include "tiled_cover/tiled_cover.h"
#include <gtest/gtest.h>
#include <string>
using std::string;
TEST(tiled_cover, test2) {
  vector<string> mat_str = {
      "010", //
      "111", //
      "010", //
      "010", //
      "111", //
      "010", //
  };
  vector<char> mat;
  for (auto &str : mat_str) {
    for (char s : str) {
      mat.push_back(s - '0');
    }
  }
  EXPECT_EQ(tiled_cover(mat, mat_str.size(), mat_str[0].size()), false);
}

TEST(tiled_cover, main) {
  string mat_str[] = {
      "0110", //
      "0111", //
      "0110", //
      "1110", //
  };
  vector<char> mat;
  for (auto &str : mat_str) {
    for (char s : str) {
      mat.push_back(s - '0');
    }
  }
  EXPECT_EQ(tiled_cover(mat, 4, mat_str[0].size()), true);
}