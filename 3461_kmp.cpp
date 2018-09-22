#include <stdio.h>
#include <string.h>
#define M 1000010
// AAA
// ABC

// A B C
// -1 0 0 0
char pattern[M],text[M];
int next[M];
void kmp(){
    int res = 0;
    // if pattern[0]...pattern[i] == text[k]...text[k + i],
    // we should check pattern[next[i]] == text[k + i + 1]
    next[0] = 0;
    int i, x;
    for(i = 1, x = 0; pattern[i]; i++){
        while(x > 0 && pattern[x] != pattern[i]){
                x = next[x - 1];
        }
        if (pattern[x] == pattern[i]){
            x++;
        }
        next[i] = x;
    }
    // for (int i = 0; i < size2; i++)
    //     printf("%d ", next[i]);
    // printf("\n");
    int k, p;
    for (k = 0, p = 0; text[k]; k++){
        while(p > 0 && text[k] != pattern[p]) p = next[p - 1];
        if (text[k] == pattern[p]){
            p++;
        }
        if (!pattern[p]){
            res++;
            p = next[p - 1];
        }
    }
    printf("%d\n", res);
}
// a b c d a b c a
// 0 0 0 0 1 2 3 1
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%s%s", pattern, text);
        //printf("%d %d\n", size1, size2);
        kmp();
    }
    return 0;
}
