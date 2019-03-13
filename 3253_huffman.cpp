#define _CRT_SECURE_NO_DEPRECATE
#include<cstdio>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    priority_queue< long long, vector<long long>, greater<long long> > fences;
    for (int i = 0; i < n; i++)
    {
        int fence;
        scanf("%d", &fence);
        fences.push(fence);
    }
    int cost = 0;
    while (fences.size() > 1)
    {
        int t1 = fences.top();
        fences.pop();
        int t2 = fences.top();
        fences.pop();
        cost += t1 + t2;
        fences.push(t1 + t2);
    }
    printf("%lld\n", cost);
}
