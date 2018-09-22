#include <iostream>

using namespace std;

int main(){
    int n;
    while (cin >> n){
        if (n == 0) break;
        int* l = new int[n];
        int* dp_max_f = new int[n - 1];
        int* dp_max_b = new int[n - 1];
        int* dp_f = new int[n - 1];
        int* dp_b = new int[n - 1];
        for (int i = 0; i < n; i++) cin >> l[i];
        dp_max_f[0] = l[0];
        dp_f[0] = l[0];
        for (int i = 1; i < n - 1; i++){
            dp_max_f[i] = dp_max_f[i - 1] > 0 ? dp_max_f[i - 1] + l[i] : l[i];
            dp_f[i] = dp_f[i - 1] > dp_max_f[i] ? dp_f[i - 1] : dp_max_f[i];
        }
        dp_max_b[n - 2] = l[n - 1];
        dp_b[n - 2] = l[n - 1];
        for (int i = 0; i < n - 2; i++){
            dp_max_b[n - 3 - i] = dp_max_b[n - 3 - i + 1] > 0 ? \
                dp_max_b[n - 3 - i + 1] + l[n - 3 - i + 1] : l[n - 3 - i + 1];
            dp_b[n - 3 - i] = dp_max_b[n - 3 - i] > dp_b[n - 3 - i + 1] ? \
                dp_max_b[n - 3 - i] : dp_b[n - 3 - i + 1];
        }
        // cout << "dp_max_f = ";
        // for (int i = 0; i < n - 1; i++){
        //     cout << dp_max_f[i] << " ";
        // }
        // cout << endl;
        // cout << "dp_f = ";
        // for (int i = 0; i < n - 1; i++){
        //     cout << dp_f[i] << " ";
        // }
        // cout << endl;
        // cout << "dp_max_b = ";
        // for (int i = 0; i < n - 1; i++){
        //     cout << dp_max_b[i] << " ";
        // }
        // cout << endl;
        // cout << "dp_b = ";
        // for (int i = 0; i < n - 1; i++){
        //     cout << dp_b[i] << " ";
        // }
        // cout << endl;
        int max_end = dp_f[0] + dp_b[0];
        for (int i = 1; i < n - 1; i++){
            if (dp_f[i] + dp_b[i] > max_end) max_end = dp_f[i] + dp_b[i];
        }
        cout << max_end << endl;
    }
    return 0;
}
