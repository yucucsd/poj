#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define M 100005
struct node
{
    int ll;
    int rr;
    int num; //color
    int cnt; //how many colors in subtrees (0, 1, 2:multiple)
}tree[8 * M];
int poster[4 * M][2], t[4 * M];
int xx[4 * M];

void create(int i, int l, int r)
{
    tree[i].ll = l;
    tree[i].rr = r;
    tree[i].cnt = 0;
    tree[i].num = 0;
    int mid = (l + r) / 2;
    if (l == r)
        return;
    create(i * 2, l, mid);
    create(i * 2 + 1, mid + 1, r);
}

int findindex(int ll, int rr, int num)
{
    while (ll <= rr)
    {
        int mid = (ll + rr) / 2;
        if (t[mid] > num)
            rr = mid - 1;
        else
            ll = mid + 1;
    }
    return rr;
}

void quest(int i)
{
    if (tree[i].cnt == 1)
    {
        xx[tree[i].num] = 1;
        return;
    }
    if (tree[i].ll == tree[i].rr)
        return;
    if (tree[i].cnt == 0)
        return;
    quest(i * 2);
    quest(i * 2 + 1);
}

void update(int i, int left, int right, int k)
{
    if (tree[i].ll == left && tree[i].rr == right)
    {
        tree[i].cnt = 1;
        tree[i].num = k;
        return;
    }
    if (tree[i].cnt == 1)
    {
        tree[i * 2].cnt = 1;
        tree[i * 2 + 1].cnt = 1;
        tree[i * 2].num = tree[i].num;
        tree[i * 2 + 1].num = tree[i].num;
        tree[i].cnt = 2;
        tree[i].num = 0;
    }
    int mid = (tree[i].ll + tree[i].rr) / 2;
    if (mid >= right)
        update(i * 2, left, right, k);
    else if (mid < left)
        update(i * 2 + 1, left, right, k);
    else
    {
        update(i * 2, left, mid, k);
        update(i * 2 + 1, mid + 1, right, k);
    }
    if (tree[i * 2].cnt == 1 && tree[i * 2 + 1].cnt == 1 &&
        tree[i * 2].num == tree[i * 2 + 1].num)
    {
        tree[i].cnt = 1;
        tree[i].num = tree[i * 2].num;
    }
    else
        tree[i].cnt = 2;
}
int main()
{
    int cases;
    scanf( "%d", &cases);
    for (; cases > 0; cases--) //for loop initialization is included in C99
    {
        int n;
        scanf("%d", &n);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &poster[i][0], &poster[i][1]);
            t[cnt++] = poster[i][0];
            t[cnt++] = poster[i][1];
        }
        sort(t, t + cnt);
        int cnt1 = 1;
        //unique
        for (int i = 1; i < cnt; i++)
            if (t[i] != t[i - 1])
                t[cnt1++] = t[i];
        //append one element if t[i] - t[i - 1] != 1
        for (int i = cnt1 - 1; i > 0; i--)
            if (t[i] != t[i - 1] + 1) 
                t[cnt1++] = t[i - 1] + 1;
        sort(t, t + cnt1);
        for (int i = cnt1; i > 0; i--)
            t[i] = t[i - 1];

        create(1, 1, cnt1 + 5);
        for (int i = 1; i <= n; i++)
        {
            int ll = 1, rr = cnt1;
            int tmp = findindex(ll, rr, poster[i - 1][0]);
            int tmp1 = findindex(ll, rr, poster[i - 1][1]);
            //printf("update[%d, %d]\n", tmp, tmp1);
            update(1, tmp, tmp1, i);
            /*for (int i = 0; i <= cnt * 5; i++)
            {
                printf("[%d, %d, num = %d, cnt: %d] ", tree[i].ls, tree[i].rd, tree[i].num, tree[i].cnt);
            }
            printf("\n");*/
        }
        
        int ans = 0;
        memset(xx, 0, sizeof(xx));
        quest(1);
        for (int i = 1; i <= n; i++)
            if (xx[i] == 1)
                ans++;
        printf("%d\n", ans);
    }
    //scanf("%d", &cases);
}