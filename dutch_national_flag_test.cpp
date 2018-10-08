#include <gtest/gtest.h>
#include <algorithm> // random_shuffle
#include <vector>
#include <iostream>
#include <numeric>

using it = std::vector<int>::iterator;

void dnf(it less, it equal, it greater, int pivot){
  while(equal <= greater){
    if(*equal < pivot){
      std::iter_swap(less, equal);
      less++;
      equal++;
    }else if(*equal == pivot){
      equal++;
    }else{
      std::iter_swap(equal, greater);
      greater--;
    }
  }
}

TEST(RandomTest, dnfTest){
  std::vector<int> v{2, 2, 0, 1, 1, 0, 2, 1, 0, 1, 0, 1, 0, 2, 2};
  int pivot = 1;
  for(int i = 0; i < 1000; i++){
    dnf(v.begin(), v.begin(), v.end()-1, 1);
    std::string output = std::accumulate(std::next(v.begin()), v.end(), 
                               std::to_string(*v.begin()),
                               [](std::string s, int i){return s+= std::to_string(i);});

    EXPECT_EQ(output, "000001111122222");
  }
}

TEST(RandomTestTwoNumbers, dnfTest){
  std::vector<int> v{0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1};
  int pivot = 1;
  for(int i = 0; i < 1000; i++){
    dnf(v.begin(), v.begin(), v.end()-1, 1);
    std::string output = std::accumulate(std::next(v.begin()), v.end(), 
                               std::to_string(*v.begin()),
                               [](std::string s, int i){return s+= std::to_string(i);});

    EXPECT_EQ(output, "000000001111111");
  }
}

TEST(RandomTestTwoNumbersMidPivot, dnfTest){
  std::vector<int> v{0, 0, 0, 0,0,9,9,9,9,9,9,9,9};
  int pivot = 1;
  for(int i = 0; i < 1000; i++){
    dnf(v.begin(), v.begin(), v.end()-1, 1);
    std::string output = std::accumulate(std::next(v.begin()), v.end(), 
                               std::to_string(*v.begin()),
                               [](std::string s, int i){return s+= std::to_string(i);});

    EXPECT_EQ(output, "0000099999999");
  }
}

TEST(RandomTestTwoNumbersHighPivot, dnfTest){
  std::vector<int> v{0, 0, 0, 0,0,9,9,9,9,9,9,9,9};
  int pivot = 10;
  for(int i = 0; i < 1000; i++){
    dnf(v.begin(), v.begin(), v.end()-1, 1);
    std::string output = std::accumulate(std::next(v.begin()), v.end(), 
                               std::to_string(*v.begin()),
                               [](std::string s, int i){return s+= std::to_string(i);});

    EXPECT_EQ(output, "0000099999999");
  }
}

int main(int argc, char**argv, char**envArg)
{
    testing::InitGoogleTest(&argc, argv);
    return(RUN_ALL_TESTS());
}