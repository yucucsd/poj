#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
/*
Floyd Warshall:
c[u][v]
for k in {1,...,n}:
    for u in V:
        for v in V:
            if c[u][v] > c[u][k] + c[k][v]:
                c[u][v] = c[u][k] + c[k][v]
traveling salseman problem
get last point
dis = min(dis(S, i) + d(i, 0));
dis(S, i) = min(dis(S - {i}, k) + d(k, i), for all k in S - {i})
*/
void renew_dis(int** dis, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                if (dis[j][k] > dis[j][i] + dis[i][k]){
                    dis[j][k] = dis[j][i] + dis[i][k];
                }
            }
        }
    }

}
int get_status(vector<int> visited, int n){
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += int(visited[i] * pow(2.0, i));
    }
    return sum;
}
void get_shortest_path(int** dis, int** dp, vector<int> &visited, int n){
    int status = get_status(visited, n);
    for (int i = 1; i < n; i++){
        if (visited[i] == 1){
            visited[i] = 0;
            int val = 0;
            int pre_status = get_status(visited, n);
            for (int j = 1; j < n; j++){
                if (visited[j] == 1){
                    if (val == 0 || val > dp[j][pre_status] + dis[j][i])
                        val = dp[j][pre_status] + dis[j][i];
                }
            }
            dp[i][status] = val;
            visited[i] = 1;
        }
    }
}
void generate_table(int** dis, int n){
    int** dp;
    dp = new int*[n];
    vector<int> visited(n);
    int status = int(pow(2.0, n));
    for (int i = 0; i < n; i++){
        dp[i] = new int[status];
        for (int j = 0; j < status; j++){
            dp[i][j] = 0;
        }
    }
    visited[0] = 1;
    for (int i = 1; i < n; i++){
        visited[i] = 1;
        int cstatus = get_status(visited, n);
        dp[i][cstatus] = dis[0][i];
        visited[i] = 0;
    }
    for (int sum = 3; sum <= n; sum++){
        for (int i = 0; i < sum; i++){
            visited[i] = 1;
        }
        do{
            get_shortest_path(dis, dp, visited, n);
        }while(prev_permutation(visited.begin() + 1, visited.end()));
    }
    // for (int i = 0; i < status; i++)
    //     cout << i << " ";
    // cout << endl;
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < status; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    int out = dis[1][0] + dp[1][status - 1];
    for (int i = 1; i < n; i++){
        if (dis[i][0] + dp[i][status - 1] < out)
            out = dis[i][0] + dp[i][status - 1];
    }
    cout << out << endl;

}
int main(){
    int n;
    int** dis;
    while(cin >> n && n != 0){
        dis = new int*[n + 1];
        for (int i = 0; i < n + 1; i++){
            dis[i] = new int[n + 1];
            for (int j = 0; j < n + 1; j++){
                cin >> dis[i][j];
            }
        }
        renew_dis(dis, n + 1);
        generate_table(dis, n + 1);
    }
}
