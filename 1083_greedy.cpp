#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        int N;
        cin >> N;
        int times[201] = {0};
        int max_val = 0;
        for (int k = 0; k < N; k++){
            int x, y;
            cin >> x >> y;
            if (x > y){
                int t = x;
                x = y;
                y = t;
            }
            for (int j = (x + 1) / 2; j <= (y + 1) / 2; j++){
                times[j] += 1;
                if (times[j] > max_val)
                    max_val = times[j];
            }
        }
        cout << max_val * 10 << endl;
    }
}
