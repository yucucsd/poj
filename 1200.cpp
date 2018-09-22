#include <stdio.h>
#include <cstring>
using namespace std;

int hash_set[16000000];
char s[1000000];
int vals[256];

int main(){
    int n, nc;
    int val = 0;
    int ans = 0;
    scanf("%d %d", &n, &nc);
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < 256; i++){
            vals[i] = -1;
    }
    for (int i = 0; i < len; i++){
        if (vals[int(s[i])] == -1){
            vals[int(s[i])] = val++;
        }
    }
    // for (int i = 0; i < len; i++){
    //     printf("%d", vals[int(s[i])]);
    // }
    // printf("\n");

    for (int i = 0; i< len - n + 1; i++){
        int new_sum = 0;
        for (int k = 0; k < n; k++){
            new_sum = new_sum * nc + vals[int(s[i + k])];
        }
        if (hash_set[new_sum] == 0){
            hash_set[new_sum] = 1;
            ans++;
        }
    }
    // for (set<int>::iterator it = sum.begin(); it != sum.end(); it++){
    //     printf("%d ", *it);
    // }
    // printf("\n");
    printf("%d\n", ans);
}
