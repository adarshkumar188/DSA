#include <stdlib.h>
#include <string.h>
char ***ans;
char **board;
int n;
int total;
int safe(int row, int col)
{
int i, j;
for (i = 0; i < row; i++)
if (board[i][col] == 'Q')
return 0;
for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
if (board[i][j] == 'Q')
return 0;
for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
if (board[i][j] == 'Q')
return 0;

    return 1;
}
void backtrack(int row)
{
int col, i;
if (row == n)
    {
ans[total] = malloc(n * sizeof(char *));
for (i = 0; i < n; i++)
 {
ans[total][i] = malloc((n + 1) * sizeof(char));
 strcpy(ans[total][i], board[i]);
 }
total++;
return;
    }
for (col = 0; col < n; col++)
{
if (safe(row, col))
{
board[row][col] = 'Q';
backtrack(row + 1);
board[row][col] = '.';
}
 }
}
char ***solveNQueens(int size, int *returnSize, int **returnColumnSizes)
{
int i, j;
n = size;
total = 0;
ans = malloc(500 * sizeof(char **));
*returnColumnSizes = malloc(500 * sizeof(int));
board = malloc(n * sizeof(char *));
for (i = 0; i < n; i++)
{
board[i] = malloc((n + 1) * sizeof(char));
for (j = 0; j < n; j++)
board[i][j] = '.';
board[i][n] = '\0';
 }
backtrack(0);
*returnSize = total;
for (i = 0; i < total; i++)
(*returnColumnSizes)[i] = n;
return ans;
}