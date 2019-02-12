#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <cstring>
#include <queue>
//#include <windows.h>
using namespace std;

int board[4] = {0, 0, 0, 0};
int state[][4] = { {8, 4, 2, 1}, {12, 14, 7, 3} };
bool same(int* board)
{
    return (board[0] == 0 || board[0] == 15) && board[1] == board[0]
        && board[2] == board[1] && board[3] == board[2];
}
void flip(int* board, int p)
{
    int r, c;
    r = p / 4;
    c = p % 4;
    board[r] ^= state[1][c];
    if (r != 0)
        board[r - 1] ^= state[0][c];
    if (r != 3)
        board[r + 1] ^= state[0][c];

}

bool find(int* board, int num, int start)
{
    if (num == 0)
        return same(board);
    for (int i = start; i < 16; i++)
    {
        flip(board, i);
        if (find(board, num - 1, i + 1))
            return true;
        flip(board, i);
    }
    return false;
}
int main()
{
    for (int i = 0; i < 4; i++)
    {
        char c;
        while ((c = getchar()) != '\n')
            if (c == 'b')
            {
                board[i] = (board[i] << 1) + 1;
            }
            else if (c == 'w')
            {
                board[i] = (board[i] << 1);
            }
    }
    for (int i = 0; i < 16; i++)
    {
        if (find(board, i, 0))
        {
            printf("%d\n", i);
            //Sleep(3000);
            return 0;
        }
    }
    printf("Impossible\n");
    //Sleep(3000);
}