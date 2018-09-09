#include <iostream>
#include <queue>
#include <algorithm>
#include <random>
#include <deque>
#include <ctime>

int main(){
  std::queue<int> q;
  srand (time(NULL));

  for(int i = 0; i <= 10; i++){
    int x = rand() % 10 + 1;
    std::cout << x <<'\n';
    q.push(x);
  }
  std::cout << "-----" << '\n';
  std::cout << q.front() <<'\n';
  std::cout << q.back() <<'\n';
  
}
