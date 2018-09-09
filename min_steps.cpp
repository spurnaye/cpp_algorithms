#include <vector>
#include <numeric>
#include <iostream>

// using namespace std; 

// int minimumSteps (vector <int> numbers ,  int input)
// {
//   std::sort(numbers.begin(), numbers.end());
//   int steps = 1;
//   int sum = numbers.front();
//   while(steps < numbers.size() && sum < input){
//     sum += numbers[steps];
//     steps++;
//     cout << (sum) << endl;
//      cout << "(sum)" << endl;
//   }
//   return --steps;
// }

// vector <int> productArray (vector <int> numbers)
// {
//   int product = std::accumulate(numbers.begin(), numbers.end(), 1, std::multiplies<int>());
//   for(int i = 0; i < numbers.size(); i++){
//     numbers[i] = product / numbers[i] ;
//   }
//   return numbers ;
// }

#include <cmath>

class Solution {
public:
    int reverse(int x) {
        if (x > pow(2, 31) - 1){
          return 0;
        }
        int length = (int)log10(abs(x));
        int reversed = 0;
        int remainder = 0;
        for(int i = length; i > 0 ; --i){
         remainder = x % 10;
         x = x / 10;
         reversed += remainder * pow(10, i);
        }
        reversed += x;
        return reversed;
    }
};

int main(){
  Solution s;
  std::cout << s.reverse(-00) << '\n';
  std::cout << s.reverse(1123) << '\n';
  std::cout << s.reverse(88989) << '\n';
}