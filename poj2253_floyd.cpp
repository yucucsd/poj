#include<cstdio>
#include<limits>
#include<algorithm>
#include <math.h>
using namespace std;

int main()
{
    int n;
    double res[500][500];
    int x[500];
    int y[500];
    int times = 1;
    while(scanf("%d", &n) && n != 0)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d %d", &x[i], &y[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                res[i][j] = double(x[j] - x[i]) * (x[j] - x[i]) + double(y[j] - y[i]) * (y[j] - y[i]);
            }
        }
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    res[i][j] = min(res[i][j], max(res[i][k], res[k][j]));
                }
            }
        }

        printf("Scenario #%d\n", times++);
        printf("Frog Distance = %.3f\n\n", sqrt(res[1][2]));
    }
}