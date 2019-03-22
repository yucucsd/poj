#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <math.h>
using namespace std;

int nodes[20];
int edges[20][20];
int flag[20];
int combination[20];
int res[20];
bool isCombine(long long t, int n, int m)
{
    long long ones = 0;
    for (int i = 0; i < n; i++)
    {
        if ((t >> i) & 1)
            ones++;
    }
    if (ones == m)
        return true;
    return false;
}
void getCombine(long long t, int n)
{
    int p = 0;
    for (int i = 0; i < n; i++)
    {
        combination[i] = 0;
        if ((t >> i) & 1)
        {
            combination[p] = i;
            p++;
        }
    }
}
long long add_node(int m)
{
    int mini, minj;
    int mine = -1;
    for (int i = 0; i < m; i++)
    {
        if (flag[i] == 1)
        {
            for (int j = 0; j < m; j++)
            {
                if (flag[j] == 0)
                {
                    if (edges[combination[i]][combination[j]] < mine || mine < 0)
                    {
                        mini = i;
                        minj = j;
                    }
                }
            }
        }
    }
    flag[minj] = 1;
    return mine;
}
long long gen_min_spantree_cost(int m)
{
    long long cost = 0;
    int mini = 0, minj = 1;
    for (int i = 0; i < m; i++)
        flag[i] = 0;
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            if (edges[combination[i]][combination[j]] < edges[combination[mini]][combination[minj]])
            {
                mini = i;
                minj = j;
            }
        }
    }
    flag[mini] = 1;
    flag[minj] = 1;
    cost += edges[combination[mini]][combination[minj]];
    int remain = m - 2;
    while (remain > 0)
    {
        cost += add_node(m);
        remain--;
    }
    return cost;
}
int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) && n && m)
    {
        for (int i = 0; i < n; ++i)
            scanf("%d", &nodes[i]);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &edges[i][j]);
        double minval = -1;
        for (int i = 0; i < pow(2, n); i++)
        {
            if (isCombine(i, n, m))
            {
                getCombine(i, n);
                /*printf("i = %d\n", i);
                for (long long j = 0; j < m; j++)
                    printf("%d ", combination[j] + 1);
                printf("\n");*/
                double nodecost = 0;
                for (int j = 0; j < m; j++)
                    nodecost += nodes[combination[j]];
                long long edgecost = gen_min_spantree_cost(m);
                if (edgecost / nodecost < minval || minval < 0)
                {
                    //printf("edgecost = %d, nodecost = %f\n", edgecost, nodecost);
                    minval = edgecost / nodecost;
                    //printf("minval = %f\n", minval);
                    for (int k = 0; k < m; k++)
                        res[k] = combination[k];
                    /*for (long long k = 0; k < m; k++)
                        printf("%d ", res[k]);
                    printf("\n");*/
                }
            }
        }
        for (int i = 0; i < m - 1; i++)
            printf("%d ", res[i] + 1);
        printf("%d\n", res[m - 1] + 1);
    }
}
