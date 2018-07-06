#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <cmath>
#include <iostream>

void primefactors(int n, std::vector<int> & factors){
  while(n % 2 == 0){
   factors.push_back(2);
   n = n /2;
  }
  for(int i = 3; i <= sqrt(n); i = i+2){
    while(n % i == 0){;
      factors.push_back(i);
      n = n / i;
    }
  }
  if(n > 2){
   factors.push_back(n);
  }
}

std::map<int, int> make_map(std::vector<int> v){
  std::map<int, int> m;
  for(auto & e:v){
    m[e] += 1;
  }
  return m;
}

std::string create_string(std::map<int, int> factors){
  std::string join_by;
  std::stringstream ss;
  for(const auto p: factors){
    if(ss.str() == ""){
      join_by = "";
    }
    else
    {
      join_by = " * ";
    }
    
    if(p.second == 1){
      ss << join_by << p.first;
    }else{
    ss << join_by << p.first << "^" << p.second;
    }
  }
  return ss.str();
}

std::string decomp(int n) {
  std::vector<int> factors;

  for(int i = 1; i <= n; i++){
    primefactors(i, factors);  
  }
  std::map<int, int> factors_map = make_map(factors);
  std::string fact_string = create_string(factors_map);
  std::cout << fact_string << '\n';
  return fact_string;
}

int main(){
  decomp(25);
}