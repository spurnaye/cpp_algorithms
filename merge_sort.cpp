#include <iostream>
#include <vector>
#include <random> // for random number generator
#include <algorithm>

using it = std::vector<int>::iterator;
using intv = std::vector<int>;

void merge(it start, it mid, it finish){
  intv left;
  intv right;

  it i;
  for(i = start;i <= mid; i++){
    left.push_back(*i);
  }
  for(;i < finish; i++){
    right.push_back(*i);
  }

  it left_start = left.begin();
  it left_end = left.end();

  it right_start = right.begin();
  it right_end = right.end();

  while(left_start != left_end && right_start != right_end){
    if(*left_start <= *right_start){
      *start = *left_start;
      ++left_start;
    }else{
      *start = *right_start;
      ++right_start;
    }
    ++start;
  }

  while(left_start < left_end){
    *start = *left_start;
    ++start;
    ++left_start;
  }

  while(right_start < right_end){
    *start = *right_start;
    start++;
    right_start++;
  }
}

void merge_sort(it start, it finish){
  it mid = start;
  if(start < finish){
    std::advance(mid, std::distance(start, finish)/2);
    merge_sort(start, mid);
    merge_sort(mid+1, finish);
    merge(start, mid, finish);
  }
}

// random generator function 
int randomfunc(int j) 
{ 
    return rand() % j; 
} 

int main(){
  intv ramdom_nums(100);
  std::iota(ramdom_nums.begin(), ramdom_nums.end(),0);
  std::random_device rd;
  std::mt19937 g(rd());
  
  std::shuffle(ramdom_nums.begin(), ramdom_nums.end(), g);

  std::cout << "Before sorting \n";
  for(const auto & i : ramdom_nums){
    std::cout << i << ' ';
  }

  merge_sort(ramdom_nums.begin(), ramdom_nums.end());

  std::cout << "\nafter sorting \n";
  for(const auto & i : ramdom_nums){
    std::cout << i << ' ';
  }
std::cout << '\n';
  return 0;
}