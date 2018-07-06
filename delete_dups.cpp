#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main(){
  std::vector<int> v(100);
  std::srand(std::time(nullptr)); // use current time as seed for random generator
  for(int i = 0; i < 100; i++){
    int random_variable = std::rand()%10;
    v.push_back(random_variable);
    std::cout << random_variable << ' ';
  }

  std::sort(v.begin(), v.end());

  v.erase( std::unique( v.begin(), v.end() ), v.end() );
  std::cout << "-----" <<'\n';
  for(const auto & i:v) std::cout << i << ' ';
}