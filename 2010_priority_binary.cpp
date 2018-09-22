#include<iostream>
#include<vector>
#include<algorithm>
#include <queue>
using namespace std;
int get_median(vector< pair<int, int> > cows, int F, int N){
    sort(cows.begin(), cows.end());
    int cost = 0;
    priority_queue<int> min_costs;
    int* min_cost_front = new int[cows.size() - N / 2 + 1];
    for (int i = 0; i < cows.size(); i++){
        if (i < N / 2) {
            cost += cows[i].second;
            min_costs.push(cows[i].second);
        }
        if (i == N / 2 - 1){
            min_cost_front[i - N / 2 + 1] = cost;
        }
        if (i >= N / 2){
            int t = min_costs.top();
            if (t > cows[i].second){
                min_costs.pop();
                min_costs.push(cows[i].second);
                cost += cows[i].second - t;
            }
            min_cost_front[i - N / 2 + 1] = cost;
        }
    }
    int cost_up = 0;
    priority_queue<int> min_costs_last;
    for (int i = cows.size() - 1; i >= cows.size() - N / 2; i--){
        cost_up += cows[i].second;
        min_costs_last.push(cows[i].second);
    }
    for (int i = cows.size() - N / 2 - 1; i >= N / 2; i--){
        if(cost_up + min_cost_front[i - N / 2] + cows[i].second <= F)
            return cows[i].first;
        if (cows[i].second < min_costs_last.top()){
            cost_up += cows[i].second - min_costs_last.top();
            min_costs_last.pop();
            min_costs_last.push(cows[i].second);
        }
    }
    return -1;
}
int main(){
    int C, N, F;
    cin >> N >> C >> F;
    vector< pair<int, int> > cows;
    for (int i = 0; i < C; i++){
        int score, cost;
        cin >> score >> cost;
        cows.push_back(pair<int, int>(score, cost));
    }
    int res = get_median(cows, F, N);
    cout << res << endl;
    return 0;
}
