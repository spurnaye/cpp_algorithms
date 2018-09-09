#include <iostream>
#include <vector>
#include <string>
 
/* A utility function to print solution */
void printSolution(std::vector<std::vector<int>> &board, int num_queens)
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
 
/* A utility function to check if a queen can
be placed on board[row][col]. Note that this
function is called when "col" queens are
already placed in columns from 0 to col -1.
So we need to check only left side for
attacking queens */
bool isSafe(std::vector<std::vector<int>> &board, int row, int col, int num_queens)
{
    int i, j;
 
    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
 
    /* Check upper diagonal on left side */
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;
 
    /* Check lower diagonal on left side */
    for (i=row, j=col; j>=0 && i<num_queens; i++, j--)
        if (board[i][j])
            return false;
 
    return true;
}
 
bool backtrack(std::vector<std::vector<int>> &board, int col, int num_queens)
{
    
    if (col == num_queens)
    {
        printSolution(board, num_queens);
        return true;
    }
 
    bool res = false;
    for (int i = 0; i < num_queens; i++){
      if (isSafe(board, i, col, num_queens)){
        board[i][col] = 1;
        backtrack(board, col + 1, num_queens) || res;
        board[i][col] = 0;
      }
    }
 
    return res;
}
 
int main()
{
    int n = 8;
    std::vector<std::vector<int>> board(n, std::vector<int>(n, 0));
    backtrack(board, 0, n);
    return 0;
}
