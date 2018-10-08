#include <iostream>
#include <vector>
#include <random>
#include <functional>
#include <numeric>
#include <algorithm>

using it = std::vector<int>::iterator;
// segregate positive and negative numbers in the vector
// the negative numbers should be at the start and positive
// numbers should be at the end
void segregate(it start, it finish){
  while(true){
    for(;*start < 0 && start < finish; start++){}
    for(;*finish > 0 && start < finish; finish--){}
    if(start < finish){
      std::iter_swap(start, finish);  
    }else{
      break;
    }
  }
}

// find max in an array
int find_max(it start, it finish, int max_num){
  if(std::next(start) == finish) return std::max(*start, *finish);
  it mid = start;
  std::advance(mid, std::distance(start,finish)/2);
  int max_left = find_max(start, mid, *start);
  int max_right = find_max(mid, finish, *mid);
  return std::max(max_left, max_right);
}

// find max sum subarray of size = k
int max_sum_k(it start, it finish, int k){
  int max_so_far = 0, sum_of_k = 0;
  for(;start < finish && start+k < finish;start++){
    sum_of_k = std::accumulate(start,start+k, 0,std::plus<int>());
    max_so_far = std::max(sum_of_k, max_so_far);
  }
  return max_so_far;
}

// find minimum index in a rotated array
int min_idx_rotated_ary(it start, it finish){
  it orig_start = start;
  if(*start < *std::prev(finish)) return 0;
  while(start < finish){
    it mid = start;
    std::advance(mid, std::distance(start, finish)/2);
    if (mid < finish && *mid > *std::next(mid)) {
      return std::distance(orig_start, mid + 1);
    }else if (*start <= *mid){
      start = std::next(mid);
    }else{
      finish =  std::prev(mid);
    }
  }
  return 0;
}

// plain vanilla binary search
int binary_search(it start, it finish, int num){
  int idx = -1;
  it orig_start = start;
  if(start > finish) return -1;

  while(start <= finish){
    it mid = start;
    std::advance(mid, std::distance(start, finish)/2);
    if(*mid == num){
      idx = std::distance(orig_start, mid);
      break;
    }else if(num < *mid){
      finish = std::prev(mid);
    }else{
      start = std::next(mid);
    }
  }
  return idx;
}

// search an element using binary search in a rotated array
int bin_search_sorted_rotated_ary(it start, it finish, int num){
  it orig_start = start;
  int idx = -1;
  while(start < finish){
    it mid = start;
    std::advance(mid, std::distance(start, finish)/2);
    
    if(*mid == num){
      idx = std::distance(orig_start, mid);
    }
   
    if(*start <= *mid){
      if(*start <= num && num <= *mid){
        finish = std::prev(mid);
      }else{
        start = std::next(mid);
      }
    }else{
       if(*mid <= num && num <= *finish){
        start = std::next(mid);
      }else{
        finish = std::prev(mid);
      }
    }
  }
  return idx;
}

// recursively find maximum in array increases first then decreases
int max_increasing_decreasing_ary(it start, it finish){
  if(start == finish){
    return *start;
  }

  if(std::next(start) == finish){
    return std::max(*start, *finish);
  }
  
  it mid = start;
  std::advance(mid, std::distance(start, finish)/2);

  if(*mid > *std::prev(mid) && *mid > *std::next(mid)){
    return *mid;
  }
  
  if(*mid > *std::next(mid) && *mid < *std::prev(mid)){
    return max_increasing_decreasing_ary(start, std::prev(mid));
   }else{
   return max_increasing_decreasing_ary(std::next(mid), finish);
   }
}

// {2,4,6,8,10,12,14,40,11,7,5,3,1}
// search = 40
int search_bitonic_ary(it start, it finish, int num){
  int max = max_increasing_decreasing_ary(start, finish);
  ptrdiff_t pos = std::distance(start, std::find(start, finish, max));
  int idx = -1;
  it orig_start = start;
  if(max == -1){
    return -1;
  }

  idx = binary_search(start, start+pos, num);
  if(idx == -1){
    start = start+pos;
    while(start <= finish){
      it mid = start;
      std::advance(mid, std::distance(start, finish)/2);
      if(*mid == num){
        idx = std::distance(orig_start, mid);
        break;
      }else if(num > *mid){
        finish = std::prev(mid);
      }else{
        start = std::next(mid);
      }
    }
  }
  return idx;
}

// {1,2,3,4,5,6,6,7,7,8,8,8,8,9,20,41,68}
int start_index_of(it start, it finish, int num){
  it orig_start = start;
  int start_idx;
  while(start < finish){
    it mid = start;
    std::advance(mid, std::distance(start,finish)/2);
    if(*mid == num && num > *std::prev(mid)){
      start_idx = std::distance(orig_start, mid);
      break;
    }else if(*mid == num && num == *std::prev(mid)){
      finish = mid;
    }else if(num > *mid){
      start = std::next(mid);
    }else{
      finish = std::prev(mid);
    }
  }
  return start_idx;
}

// {1,2,3,4,5,6,6,7,7,8,8,8,8,9,20,41,68}
int end_index_of(it start, it finish, int num){
  it orig_start = start;
  int end_idx;
  while(start < finish){
    it mid = start;
    std::advance(mid, std::distance(start, finish)/2);
    if(*mid == num && num < *std::next(mid)){
      end_idx = std::distance(orig_start, mid);
      break;
    }else if(*mid == num && num < *std::next(mid)){
      start = mid;
    }else if(num < *mid){
      start = std::next(mid);
    }else{
      finish = std::prev(mid);
    }
  }
  return end_idx;
}

int main(){
  std::vector<int> numbers {-1, 3, 8, -4, 5, -6, 7, -20, 30, -40};
  segregate(numbers.begin(), numbers.end());
  for(const int & i: numbers) std::cout << i <<  ' ';
  std::cout << '\n';


  std::random_device rd;  //Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<> dis(1, 200);

  std::vector<int> nums_find_max {8, 4, 2, 1};
  for (int n=0; n<20; ++n){
      int num = dis(gen);
      std::cout << num << ' ';
      nums_find_max[n] = num;
  }

  std::cout << '\n';
  std::cout << "Max number is : " << find_max(nums_find_max.begin(), 
                                              nums_find_max.end(), 
                                              *nums_find_max.begin()) << '\n';


  std::vector<int> v_max_k{11, -8, 16, -7, 24, -2, 3};
  std::cout << max_sum_k(v_max_k.begin(), v_max_k.end(), 3) << '\n';  // 33

  std::vector<int> rotated{65, 70, 80, 90, 10, 20, 30, 40, 50, 60};
  std::cout << min_idx_rotated_ary(rotated.begin(), rotated.end()) << '\n';

  std::vector<int> bin_search{10, 20, 30, 40, 50, 60, 65, 70, 80, 90};
  std::cout << binary_search(bin_search.begin(), bin_search.end(), 70) << '\n';
  std::cout << binary_search(bin_search.begin(), bin_search.end(), 100) << '\n';

  std::cout << bin_search_sorted_rotated_ary(rotated.begin(), rotated.end(), 80) << '\n';
  std::cout << bin_search_sorted_rotated_ary(rotated.begin(), rotated.end(), 65) << '\n';
  std::cout << bin_search_sorted_rotated_ary(rotated.begin(), rotated.end(), 30) << '\n';

  std::vector<int> increasing_decreasing_ary{2,4,6,8,10,12,14,40,11,7,5,3,1};
  std::cout << "max in increasing and then decreasing ary :" << max_increasing_decreasing_ary(increasing_decreasing_ary.begin(),
    increasing_decreasing_ary.end()) << '\n';

  std::cout << "index of 40 in bitonic_ary "<<search_bitonic_ary(increasing_decreasing_ary.begin(), 
                                  increasing_decreasing_ary.end(),
                                  40) << '\n';


  std::cout << "index of 7 in bitonic_ary " << search_bitonic_ary(increasing_decreasing_ary.begin(), 
                                  increasing_decreasing_ary.end(),
                                  7) << '\n';

  std::vector<int> mid_repeating{1,2,3,4,5,6,6,7,7,8,8,8,8,9,20,41,68};
  int start_idx = start_index_of(mid_repeating.begin(), mid_repeating.end(), 8);
  int end_idx = end_index_of(mid_repeating.begin()+8, mid_repeating.end(), 8) + start_idx;

  int count_8 = end_idx - start_idx;
  std::cout << "start index of 8 "<< start_idx << '\n';
  std::cout << "end index of 8 "<< end_idx << '\n';
  std::cout << "count of 8 :" << count_8 << '\n';
}