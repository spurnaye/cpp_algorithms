#include <iostream>
#include <algorithm>
#include <string>

template <typename T>
void reverse_rotate(T first, T last){
  if((first == last) || std::next(first) == last) return;
  T middle = first;
  std::advance(middle, std::distance(first, last)/2);
  reverse_rotate(first, middle);
  reverse_rotate(middle, last);
  std::rotate(first, middle, last);
}

int main(){
  std::string s = "This is super cool";
  reverse_rotate(s.begin(), s.end());
  std::cout << s << '\n';
}