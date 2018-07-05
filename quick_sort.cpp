#include <vector>
#include <iostream>
#include <algorithm>

auto partition(std::vector<int>::iterator start, std::vector<int>::iterator end_it){
  auto partition_idx = start;
  for(auto i = start; i != end_it; i++){
    if(*i <= *end_it){
      std::iter_swap(i, partition_idx);
      partition_idx++;
    }
  }
  std::iter_swap(partition_idx, end_it);
  return partition_idx;
}

void quick_sort(std::vector<int>::iterator start,std::vector<int>::iterator end_it){
  int size = std::distance(start, end_it);
  if (size <= 1) return;
  auto partition_idx = partition(start, end_it);
  quick_sort(start, partition_idx-1);
  quick_sort(partition_idx, end_it);
}

int main(){
  std::vector<int> v{72, 23, 65, 53, 36, 90, 76, 50, 1, 20, 64, 18, 26, 39, 34, 91, 86, 21, 81, 7, 58, 27, 9, 61, 77, 2, 88, 70, 79, 3, 100, 44, 94, 51, 83, 48, 68, 13, 96, 30, 98, 24, 95, 67, 55, 8, 56, 19, 52, 85, 6, 69, 43, 16, 93, 74, 60, 41, 37, 84, 66, 99, 78, 57, 33, 14, 62, 35, 31, 46, 59, 38, 12, 92, 73, 25, 32, 22, 28, 63, 54, 97, 29, 47, 15, 40, 87, 80, 17, 71, 11, 4, 75, 89, 49, 10, 5, 45, 42, 82};
  quick_sort(v.begin(), v.end()-1);
  for(const auto & i:v){
    std::cout << i << ' ';
  }
  return 0;
}