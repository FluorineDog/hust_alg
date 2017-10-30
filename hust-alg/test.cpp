#include "tiled_cover/tiled_cover.h"
#include <gtest/gtest.h>
#include <string>
using std::string;
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

TEST(tiled_cover, test3) {
  vector<string> mat_str = {
      "110101111", //
      "111111111", //
      "110101111", //
      "110101111", //
      "111111111", //
      "110101111", //
  };
  vector<char> mat;
  for (auto &str : mat_str) {
    for (char s : str) {
      mat.push_back(s - '0');
    }
  }
  EXPECT_EQ(tiled_cover(mat, mat_str.size(), mat_str[0].size()), true);
}

TEST(tiled_cover, test4) {
  vector<string> mat_str = {
      "1100101111", //
      "1101111111", //
      "1100101111", //
      "1100101111", //
      "1101111111", //
      "1100101111", //
  };
  vector<char> mat;
  for (auto &str : mat_str) {
    for (char s : str) {
      mat.push_back(s - '0');
    }
  }
  EXPECT_EQ(false, tiled_cover(mat, mat_str.size(), mat_str[0].size()));
}


#include "interval_cover/interval_cover.h"
TEST(interval_cover, test0) {
  vector<Data> data{
      {1, 1, 2.0}, //
      {2, 3, 2.0}, //
      {3, 4, 2.0}, //
      {1, 4, 5.0}, //
      {0, 1, 1.0}, //
  };
  int sum = interval_cover(std::move(data));
  EXPECT_EQ(sum, 7);
}

// second trial
#include <algorithm>
#include <chrono>
#include <cinttypes>
#include <cstdio>
#include <memory>
#include <utility>
#include <vector>
using namespace std;

TEST(interval_cover, test1) {
  unique_ptr<FILE, decltype(&fclose)> fp{fopen("p3-in-big.dat", "rb"), &fclose};
  uint32_t n;
  fread(&n, 4, 1, fp.get());
  vector<Data> data(n);
  fread(data.data(), 8, 3 * n, fp.get());
  for(int i = 0; i < n; ++i){
    std::swap(std::get<0>(data[i]), std::get<2>(data[i]));
  }
  auto t1 = chrono::high_resolution_clock::now();
  int sum = interval_cover(data);
  auto t2 = chrono::high_resolution_clock::now();
  auto time = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
  cerr << "fake";
  cerr << sum << "fake" << time << endl;
}
