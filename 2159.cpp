#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    string a, b;
    cin >> a;
    cin >> b;
    if (a.size() != b.size()){
        cout << "NO" << endl;
        return 0;
    }
    vector<int> ai(26, 0);
    vector<int> bi(26, 0);
    for (int i = 0; i < b.size(); i++){
        ai[a[i] - 'A'] ++;
        bi[b[i] - 'A'] ++;
    }
    sort(ai.begin(), ai.end());
    sort(bi.begin(), bi.end());
    for (int i = 0; i < 26; i++){
        if (ai[i] != bi[i]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
