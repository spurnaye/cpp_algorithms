#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <stdlib.h>
#include <functional>


class Kata{

static int charToInt(char & c){
  return c - '0';
}

static bool oddNum(int i){
  return (i % 2) == 1;
}

static int additionAboveNine(std::string digitStr){
  std::vector<int> digitsVect;
      for(char & c: digitStr){
            int i = charToInt(c);
            digitsVect.push_back(i);
            }
      return std::accumulate(digitsVect.begin(),
                      digitsVect.end(),
                      0,
                      std::plus<int>());
 }

static int doubleAtOddIteration(int iteration, int num){
  return oddNum(iteration) ? num : num  * 2;
}

static int doubleAtEvenIteration(int iteration, int num){
  return oddNum(iteration) ? num * 2: num;
}

static int doubleNumbers(std::string numStr, bool isOdd){
  std::vector<int> sums;
  int iteration = 1;
  for(char & c: numStr){
    int i = charToInt(c);
    i = isOdd ? doubleAtOddIteration(iteration, i) : doubleAtEvenIteration(iteration, i);
    if (i > 9){
      std::string digitStr = std::to_string(i);
      i = additionAboveNine(digitStr);
    }
    ++iteration;
    sums.push_back(i);
  }
  return std::accumulate(sums.begin(), sums.end(), 0, std::plus<int>());;
}

  static bool oddDigits(std::string numStr){
    return (numStr.length() % 2 == 1);
  }

public:
    static bool validate(long long int n) {
    std::string numStr = std::to_string(n);
    int sumofDigits = oddDigits(numStr) ? doubleNumbers(numStr, true) : doubleNumbers(numStr, false);
    return ((sumofDigits % 10) == 0) ? true : false;
  }
};


int main(){
  bool x;
  std::cout << std::boolalpha << std::endl;
  std::cout << Kata::validate(891) << "\n";
  std::cout << Kata::validate(2121) << std::endl;
  return 0;
}

