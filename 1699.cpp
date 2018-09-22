#include <iostream>
#include <string.h>
using namespace std;
int get_cover(char* end, char* dna, int len){
    for (int i = len; i >= 0; i--){
        int cover = 1;
        for (int k = 1; k <= i; k++){
            if (dna[i - k] != end[len - k]) cover = 0;
        }
        if (cover == 1){
            return i;
        }
    }
    return 0;
}
int get_shortest_length(int len, char** dna, char* res, int sn, int* contained, int sum){
    if (sum == sn) {
        return 0;
    }
    int min_len = 20 * sn;
    for (int i = 0; i < sn; i++){
        if (contained[i] == 1) continue;
        int dnalen = strlen(dna[i]);
        if (len == 0){
            for (int k = 0; k < dnalen; k++){
                res[k] = dna[i][k];
            }
            len += dnalen;
            contained[i] = 1;
            sum ++;
            int rest_len = get_shortest_length(len, dna, res, sn, contained, sum);
            if (rest_len + dnalen < min_len){
                min_len = rest_len + dnalen;
            }
            len -= dnalen;
            contained[i] = 0;
            sum--;
        }else{
            char* end = res + len - dnalen;
            for (int k = 0; k < dnalen; k++){
                end[k] = res[len - dnalen + k];
            }
            int cover = get_cover(end, dna[i], dnalen);
            strcpy(res + len, dna[i] + cover);
            // for (int k = 0; k < dnalen - cover; k++){
            //     res[len + k] = dna[i][cover + k];
            // }
            len += dnalen - cover;
            contained[i] = 1;
            sum ++;
            int rest_len = get_shortest_length(len, dna, res, sn, contained, sum);
            if (rest_len + dnalen - cover < min_len){
                min_len = rest_len + dnalen - cover;
            }
            len -= dnalen - cover;
            contained[i] = 0;
            sum--;
        }
    }
    return min_len;

}

int main(){
    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        int sn;
        cin >> sn;
        char** dna = new char*[sn];
        int* contained = new int[sn];
        for (int k = 0; k < sn; k++){
            dna[k] = new char[20];
            cin >> dna[k];
            contained[k] = 0;
        }
        int len = 0, sum = 0;
        char* res = new char[20 * sn];
        int res_len = get_shortest_length(len, dna, res, sn, contained, sum);
        cout << res_len << endl;
        delete dna;
        delete contained;
        delete res;
    }
}
