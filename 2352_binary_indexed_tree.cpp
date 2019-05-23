#define _CRT_SECURE_NO_DEPRECATE
#include<cstdio>
#include<cstring>
using namespace std;
int c[32005], level[32005];

inline int lowerbit(int x) { return x & (-x); }

int sum(int x)
{
    int v = 0;
    while (x)
    {
        v += c[x];
        x -= lowerbit(x);
    }
    return v;
}
void add(int x)
{
    while (x < 32005)
    {
        c[x]++;
        x += lowerbit(x);
    }
}
int main()
{
    int n, x, y;
    memset(c, 0, sizeof(c));
    memset(level, 0, sizeof(c));
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        x++;
        level[sum(x)]++;
        add(x);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", level[i]);
    }
}
