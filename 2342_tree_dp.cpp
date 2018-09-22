#include <iostream>
#include <vector>
using namespace std;
int vals[6000];
int dp[6000][2];
int n;
vector< vector<int> > edges(6000);
void dfs(int r){
    if(edges[r].size() != 0){
        for (int i = 0; i < edges[r].size(); i++){
            int x = edges[r][i];
            dfs(x);
            dp[r][0] += max(dp[x][0], dp[x][1]);
            dp[r][1] += dp[x][0];
        }
    }
}
int main(){
    cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++){
        cin >> dp[i][1];
        dp[i][0] = 0;
    }
    int ee, er;
    while(cin >> ee >> er && ee != 0 && er != 0){
        edges[er - 1].push_back(ee - 1);
        v[ee-1]++;
    }
    int root = 0;
    for(int i = 0; i < n; i++){
        if (!v[i]){
            root = i;
            break;
        }
    }
    dfs(root);
    cout << max(dp[root][0], dp[root][1]) << endl;
    return 0;
}
