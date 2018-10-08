#include <iostream>
#include <vector>

int main(){
  std::vector<std::vector<int>> v(8, std::vector<int>(8, 0));
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      v[i][j]= (i+1)*(j+1);
    }
  }


  // printing the matrix
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      std::cout << v[i][j] << '\t';
    }
    std::cout << '\n';
  }

  int row, col;
  int rowCount = v.size();
  int columnCount = v[0].size();
 
  for(int k = 0; k < rowCount; k++){
    for(row = k, col = 0; row >= 0 && col <= columnCount; row --, col++){
      std::cout << v[row][col] << '\t';
    }
    std::cout << '\n';
  }

  for(int k = 0; k < rowCount; k++){
    for(row = rowCount -1, col = k; row >= 0 && col <= columnCount; row --, col++){
      std::cout << v[row][col] << '\t';
    }
    std::cout << '\n';
  }

  return 0;
}