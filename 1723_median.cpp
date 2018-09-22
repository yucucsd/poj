#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void get_soldiers(vector<int>& xs, vector<int>& ys, int n, int& res){
    nth_element(ys.begin(), ys.begin() + n/2, ys.end());
    int y = ys[n/2];
    sort(xs.begin(), xs.end());
    for (int i = 0; i < n; i++){
        xs[i] -= i;
    }
    // x = start, is the median of xs min \sum |x_i - (start + i)| = min \sum |(x_i - i) - start|
    nth_element(xs.begin(), xs.begin() + n/2, xs.end());
    int x = xs[n/2];
    for (int i = 0; i < n; i++){
        res += abs(ys[i] - y);
        res += abs(xs[i] - x);
    }
}

int main(){
    vector<int> xs;
    vector<int> ys;
    int res = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        xs.push_back(x);
        ys.push_back(y);
    }
    get_soldiers(xs, ys, n, res);
    cout << res << endl;
    return 0;
}
