#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <math.h>
#include <algorithm>
using namespace std;
#define maxn 50002
int minh[maxn][21];
int maxh[maxn][21];

void init_st(int row)
{
    for (int i = 1; (1 << i) < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            minh[j][i] = (j + (1<<(i - 1))) >= row ? minh[j][i - 1] : min(minh[j][i - 1], minh[j + (1 << (i - 1))][i - 1]);
            maxh[j][i] = (j + (1 << (i - 1))) >= row ? maxh[j][i - 1] : max(maxh[j][i - 1], maxh[j + (1 << (i - 1))][i - 1]);
        }
    }
}

int query(bool m, int l, int r)
{
    int k = 0;
    while ((1 << (k + 1)) <= r - l + 1)
        k++;
    if (m)
        return max(maxh[l][k], maxh[r - (1 << k) + 1][k]); //2^(k + 1) > r - l + 1
    else
        return min(minh[l][k], minh[r - (1 << k) + 1][k]);
}
int main()
{
    int N, Q;
    scanf("%d %d", &N, &Q);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &minh[i][0]);
        maxh[i][0] = minh[i][0];
    }
    init_st(N);
    while (Q--)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        l--, r--;
        int valmax = query(true, l, r);
        int valmin = query(false, l, r);
        //printf("min= %d, max = %d, %d\n", valmin, valmax, valmax - valmin);
        printf("%d\n", valmax - valmin);
    }
    //scanf("%d", &N);
}