#include<iostream>

using namespace std;
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int length;
        cin >> length;
        int* sequence = new int[length];
        int sum = 0;
        int black_even = 0;
        for (int i = 0; i < length; i++){
            cin >> sequence[i];
            sum += sequence[i];
            if ((i & 1) && sequence[i]) black_even++;
        }
        if (length & 1) cout << "YES" << endl;
        else{
            int rest = sum - black_even;
            int diff = black_even > rest ? black_even - rest : rest - black_even;
            if (diff < 2) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}
