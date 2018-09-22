//unfinished
#include <cstdio>
#include <cstring>
long long f[30][1<<12], i, j, m, n, saya = 1;
void sayatime(int i, int s1, int pos){// fill line i to pattern from s1 to 1 << m from pos to m
    if (pos == m) {f[i][s1] += saya; return;}
    sayatime(i, s1, pos + 1);
    if (pos <= m - 2 && !(s1 & 1 << pos) && !(s1 & 1 << pos + 1)) sayatime(i, s1 | 1<<pos | 1 << pos + 1, pos + 2);
}
int main(){
    while(scanf("%d%d", &n, &m), n != 0){
        memset(f, 0, sizeof(f)); saya = 1;
        sayatime(1, 0, 0);
        for (int i = 2; i <= n; i++){
            for (int j = 0; j < 1 << m; j++){
                if (f[i - 1][j]) saya = f[i - 1][j]; else continue;
                sayatime(i, ~j&((1 << m) - 1), 0); //~j if i-1 didn't fill k in status j, i needs to fill it
            }
        }
        printf("%lld\n", f[n][(1<<m) - 1]);
    }
}
