#include <string>
#include <stack>
#include <iostream>

int solve(std::string str, int index){
  std::cout << str << std::endl;
  if(str.at(index) != '('){
    return -1;
  }
  std::stack<char> brackets;
  int endBracketIndex;
  for(int i = index; i < str.length(); ++i){
    char c = str.at(i);
    std::cout << c << std::endl;
    if (c == '('){
      brackets.push('(');
    }else if(c == ')' && brackets.top() == '('){
      endBracketIndex = i;
      brackets.pop();
      if (brackets.size() == 0){
        break;
      }
    }
  }
  return endBracketIndex;
}

#include <vector>
int main(){
  std::vector<int> v{1,2,3,4,5,6,7};
  std::cout << v.size() - 2  << std::endl;
}