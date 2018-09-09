#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

template <typename T>
bool check_sorted(T start, T finish, bool sorted = true){
  if(start == finish) return true;

  if(std::next(start) == finish) return *start <= *finish;

  T middle = start;
  std::advance(middle, std::distance(start, finish)/2);

  sorted &= check_sorted(start, middle);
  sorted &= check_sorted(middle, finish-1);
  return sorted;
}

int main(){
   std::vector<int> v(20);
   std::iota(v.begin(), v.end(), 1);
   bool sorted = check_sorted(v.begin(), v.end());
   std::cout << "v is sorted? : " << sorted << '\n';

  std::vector<int> v2 {20, 1, 3, 5, 2, 1, 4, 19, 18, 10};
  sorted = check_sorted(v2.begin(), v2.end());
  std::cout << "v2 is sorted?: " << sorted << '\n';


  std::vector<int> v3 {1,1,1,1,1,1,1,1,1,1,1,1,1,1};
  sorted = check_sorted(v3.begin(), v3.end());
  std::cout << "v3 is sorted?: " << sorted << '\n';

  std::vector<int> v4 {10,1,1,1,1,1,1,1,1,1,1,1,1,1};
  sorted = check_sorted(v4.begin(), v4.end());
  std::cout << "v4 is sorted?: " << sorted << '\n';
}