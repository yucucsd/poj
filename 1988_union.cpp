#include<stdio.h>
int pa[30050];
int num[30050];
int under[30050];
int root(int x){
    int tmp = pa[x];
    if (pa[x] != x){
        pa[x] = root(pa[x]);
        under[x] += under[tmp];
    }
    return pa[x];
}
void union_set(int x, int y){
    int t1 = root(x);
    int t2 = root(y);
    if (t1 == t2) return;
    pa[t1] = t2;
    under[t1] +=num[t2];
    num[t2] += num[t1];

}
int main(){
    int P;
    scanf("%d", &P);
    for (int i = 0; i < 30050; i++){
        pa[i] = i;
        num[i] = 1;
        under[i] = 0;
    }
    for (int i = 0; i < P; i++){
        char a;
        scanf("\n%c", &a);
        if (a == 'M'){
            int x, y;
            scanf("%d %d", &x, &y);
            union_set(x, y);
        }
        if (a == 'C'){
            int x;
            scanf("%d", &x);
            root(x);
            printf("%d\n", under[x]);
        }
    }
    return 0;
}
// for (int i = 0; i < 7; i++){
//     cout << r[i] << " ";
// }
// cout << endl;
// for (int i = 0; i < 7; i++){
//     cout << dis[i] << " ";
// }
// cout << endl;
// for (map< int, vector<int> >::iterator it = u.begin(); it != u.end(); it++){
//     cout << it->first << ": ";
//     for (int i = 0; i < (it->second).size(); i++)
//         cout << (it->second)[i] << " ";
//     cout << endl;
// }
