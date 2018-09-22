#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
 struct node{
    bool root;
    std::vector<int> children;
};
node v[10001];
int search (int s1, int s2, struct node* v, int r){
    if (r == s1) return r;
    if (r == s2) return r;
    std::vector<int> found;
    for (int i = 0; i < v[r].children.size();i++){
        found.push_back(search(s1, s2, v, v[r].children[i]));
    }
    int u = 0, l = 0;
    for (int i = 0; i < found.size(); i++){
        if (found[i] != 0){
            if (u) l = found[i];
            else u = found[i];
        }
    }
    if (l) return r;
    else if (u) return u;
    else return 0;
}
void solve(){
    int N;
    scanf("%d", &N);
    memset(v, 0, sizeof(v));
    for (int i = 0; i < N; i++)
        v[i].root = true;
    for (int i = 0; i < N - 1; i++){
        int pa, ch;
        scanf("%d %d", &pa, &ch);
        pa--, ch--;
        v[pa].children.push_back(ch);
        v[ch].root = false;
    }
    int r = 0;
    for (int i = 0; i < N; i++){
        if (v[i].root){
            r = i;
            break;
        }
    }
    int s1, s2;
    scanf("%d %d", &s1, &s2);
    s1--, s2--;
    r = search(s1, s2, v, r);
    printf("%d\n", r + 1);
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        solve();
    }
    return 0;
}
