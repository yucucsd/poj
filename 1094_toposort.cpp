#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <cstring>
using namespace std;

int edge[26][26], in[26], p[26];

int topoSort(int n)
{
    int temp[26];
    memcpy(temp, in, 26 * sizeof(int));
    int c = 0;
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        int start = 0, loc;
        for (int j = 0; j < n; j++)
        {
            if (temp[j] == 0)
            {
                start++;
                loc = j;
            }
        }
        if (start == 0)
            return 0;
        if (start > 1)
            flag = -1;
        p[c++] = loc;
        temp[loc] = -1;
        for (int k = 0; k < 26; k++)
        {
            if (edge[loc][k] == 1)
                temp[k]--;
        }
    }
    return flag;
}
int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) && n != 0 && m != 0)
    {
        bool res = false;
        memset(edge, 0, 26 * 26 * sizeof(int));
        memset(p, 0, 26 * sizeof(int));
        memset(in, 0, 26 * sizeof(int));
        for (int i = 0; i < m; i++)
        {
            char line[5];
            scanf("%s", line);
            if (res) continue;
            edge[(int)(line[0] - 'A')][(int)(line[2] - 'A')] = 1;
            in[(int)(line[2] - 'A')] += 1;
            int r = topoSort(n);
            if (r == 0)
            {
                printf("Inconsistency found after %d relations.\n", i + 1);
                res = true;
            }
            else if (r == 1)
            {
                printf("Sorted sequence determined after %d relations: ", i + 1);
                for (int j = 0; j < n; j++)
                    printf("%c", (char)(p[j] + 'A'));
                printf(".\n");
                res = true;
            }
        }
        if (!res)
            printf("Sorted sequence cannot be determined.\n");
    }
}