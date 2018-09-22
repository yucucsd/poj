#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main(){
    int n;
    while (cin >> n && n != 0){
        int square = 0;
        pair<int, int>* p = new pair<int, int>[n];
        for (int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            p[i] = pair<int, int>(x, y);
        }
        sort (p, p + n);
        for (int it1 = 0; it1 != n; it1++){
            int it2 = it1 + 1;
            while(it2 != n){
                int x_diff = p[it2].first - p[it1].first;
                int y_diff = p[it2].second - p[it1].second;
                // cout << "Points: " << endl;
                // cout << p[it1].first << " " << p[it1].second << endl;
                // cout << p[it2].first << " " << p[it2].second << endl;
                // cout << endl;
                pair<int, int> point3, point4;
                if (y_diff >= 0){
                    point3 = pair<int, int>(p[it1].first + y_diff, p[it1].second - x_diff);
                    point4 = pair<int, int>(p[it2].first + y_diff, p[it2].second - x_diff);
                }else{
                    point3 = pair<int, int>(p[it1].first - y_diff, p[it1].second + x_diff);
                    point4 = pair<int, int>(p[it2].first - y_diff, p[it2].second + x_diff);
                }
                bool exist = binary_search(p, p + n, point3) && binary_search(p, p + n, point4);
                if (exist) square += 1;
                it2++;
            }
        }
        cout << square / 2 << endl;
    }
}
