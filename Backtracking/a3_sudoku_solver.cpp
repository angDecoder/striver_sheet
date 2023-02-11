#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int

bool isValid(int i, int j, char num, vector<vector<char>> &board)
{
    int n = board.size();
    for (int p = 0; p < n; p++)
    {
        if (board[p][j] == num)
            return false;
    }

    for (int q = 0; q < n; q++)
    {
        if (board[i][q] == num)
            return false;
    }

    i -= i % 3, j -= j % 3;
    for (int p = i; p < i + 3; p++)
    {
        for (int q = j; q < j + 3; q++)
        {
            if (board[p][q] == num)
                return false;
        }
    }

    return true;
}

bool solve(int i, int j, vector<vector<char>> &board)
{
    int n = board.size();
    if (j == n)
        j = 0, i++;
    if (i == n)
        return true;

    if (board[i][j] != '.')
        return solve(i, j + 1, board);

    for (char num = '1'; num <= '9'; num++)
    {
        if (!isValid(i, j, num, board))
            continue;

        board[i][j] = num;
        if (solve(i, j + 1, board))
            return true;
        board[i][j] = '.';
    }

    return false;
}

void solveSudoku(vector<vector<char>> &board)
{
    solve(0, 0, board);
}

int main()
{

    return 0;
}