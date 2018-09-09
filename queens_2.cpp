#include <iostream>
#include <vector>
#include <string>
 
/* A utility function to print solution */
void print_solution(std::vector<std::vector<int>> &board, int num_queens)
{
    static int k = 1;
    printf("%d-\n",k++);
    for (int i = 0; i < num_queens; i++)
    {
        for (int j = 0; j < num_queens; j++)
          if(board[i][j] == 1)
            printf(" Q ");
          else
            printf(" . ");
        printf("\n");
    }
    printf("\n");
}
 
bool is_safe(std::vector<std::vector<int>> &board, int row, int current_iteration, int num_queens){
    
}

bool backtrack(std::vector<std::vector<int>> &board, int current_iteration, int num_queens){
    if(current_iteration == num_queens){
        print_solution(board, num_queens)
    }
    
    bool result = false;
    for(int i = 0; i < num_queens; i++){
        if(is_safe(board,i, current_iteration, num_queens)){
           board[i][current_iteration] = 1;
           result =  is_safe(board,i, current_iteration, num_queens) || result;
           board[i][current_iteration] = 0;
        }
    }
    return result;
}

int main()
{
    int n = 8;
    std::vector<std::vector<int>> board(n, std::vector<int>(n, 0));
    backtrack(board, 0, n);
    return 0;
}
