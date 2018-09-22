#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class team{
public:
    int c, num, wrong;
    int solved[20];
    double time_s[20];
    double time_total;
    team();
    void get_total_time();
};
team::team(){
    num = 0;
    time_total = 0;
    for (int i = 0; i < 20; i++){
        solved[i] = 0;
        time_s[i] = 601;
    }
}
void team::get_total_time(){
    for (int i = 0; i < 20; i++){
        if (solved[i] == 1)
            time_total += time_s[i];
    }
    time_total += wrong * 20;
}

bool cmp(team a, team b){
    if (a.num > b.num)
        return true;
    if (a.num == b.num){
        if (a.time_total < b.time_total)
            return true;
        else if (a.time_total == b.time_total)
            return a.c < b.c;
        else
            return false;
    }
    return false;
}
int main(){
    int C, N;
    cin >> C >> N;
    vector<team> t(C);
    for (int i = 0; i < C; i++)
        t[i].c = i;
    int* ci = new int[N];
    int* pi = new int[N];
    int* ti = new int[N];
    int* ri = new int[N];

    for (int i = 0; i < N; i++){
        cin >> ci[i] >> pi[i] >> ti[i] >> ri[i];
    }
    for (int i = 0; i < N; i++){
        if (ri[i] == 1){
            if (t[ci[i] - 1].solved[pi[i] - 1] == 0){
                t[ci[i] - 1].num += 1;
                t[ci[i] - 1].solved[pi[i] - 1] = 1;
            }
            t[ci[i] - 1].time_s[pi[i] - 1] = min(double(ti[i]) / 60, t[ci[i] - 1].time_s[pi[i] - 1]);
        }
    }
    for (int i = 0; i < N; i++){
        if (ri[i] == 0){
            if (t[ci[i] - 1].solved[pi[i] - 1] == 1){
                if (double(ti[i]) / 60 < t[ci[i] - 1].time_s[pi[i] - 1]){
                    t[ci[i] - 1].wrong += 1;
                }
            }
        }
    }
    for (int i = 0; i < C; i++){
        t[i].get_total_time();
    }
    sort(t.begin(), t.end(), cmp);
    cout << t[0].c + 1;
    for (int i = 1; i < C; i++){
        cout << " " << t[i].c + 1;
    }
    cout << endl;
}
