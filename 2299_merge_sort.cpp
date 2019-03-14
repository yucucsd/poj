#define _CRT_SECURE_NO_DEPRECATE
#define MAXLENGTH 500001
#include <cstdio>
using namespace std;
int num[MAXLENGTH];
int temp[MAXLENGTH];
void merge(int* num, int start, int end, int middle, long long& times)
{
    if (end - start <= 1)
        return;
    int add = 0;
    int k = 0;
    int p = 0;
    for (int i = 0; i < middle - start; i++)
    {
        while (p < end - middle && num[middle + p] < num[start + i])
        {
            temp[k] = num[middle + p];
            p++;
            add++;
            k++;
        }
        times += add;
        temp[k] = num[start + i];
        k++;
    }
    if (p < end - middle)
    {
        for (; k < end - start; k++)
        {
            temp[k] = num[middle + p];
            p++;
        }
    }
    for (int i = start; i < end; i++)
        num[i] = temp[i - start];
}

void merge_sort(int* num, int start, int end, long long& times)
{
    if (end - start == 1)
    {
        return;
    }
    merge_sort(num, start, start + (end - start) / 2, times);
    merge_sort(num, start + (end - start) / 2, end, times);
    merge(num, start, end, start + (end - start) / 2, times);
}

int main()
{
    int n;
    
    while (scanf("%d", &n) && n != 0)
    {
        long long times = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
        }
        merge_sort(num, 0, n, times);
        printf("%lld\n", times);
    }
}
