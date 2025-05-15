#include <stdio.h>
#include <stdbool.h>

#define N 4

int board[N][N];

bool isSafe(int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return false;
    return true;
}
bool solveNQueens(int col) {
    if (col >= N)
        return true;
    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;

            if (solveNQueens(col + 1))
                return true;

            board[i][col] = 0;
        }
    }
    return false;
}
void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}
int main() {
    if (solveNQueens(0))
        printBoard();
    else
        printf("No solution exists.\n");
    return 0;
}
