#include <iostream>
#include <vector>
#include <string>
#include <numeric>

std::string looknsay(int num){
  std::vector<std::vector<int>> look_n_say_seq{{1}};
  for(int n = 0; n <= num; n++){
    auto latest_sequence = look_n_say_seq.back();
    std::vector<int> next_sequence;
    auto i = latest_sequence.begin();
    auto j = latest_sequence.begin();
    while(i < latest_sequence.end()){
      for(;*i==*j && j < latest_sequence.end();++j){}
      next_sequence.push_back(std::distance(i, j));
      next_sequence.push_back(*i);
      i = j;
    }
    look_n_say_seq.push_back(next_sequence);

  }
  auto latest_sequence = look_n_say_seq.back();
  return std::accumulate(std::next(latest_sequence.begin()), 
                         latest_sequence.end(),
                          std::to_string(*latest_sequence.begin()),
                          [](std::string s, int i){return s += std::to_string(i);});
}
int main(){
  std::cout << looknsay(0) << '\n';
  std::cout << looknsay(1) << '\n'; // 11
  std::cout << looknsay(2) << '\n'; // 21
  std::cout << looknsay(3) << '\n'; // 1211
  std::cout << looknsay(4) << '\n'; // 111221
  std::cout << looknsay(5) << '\n'; // 312211
}