#include<iostream>
#include<stdlib.h>
using namespace std;
/*
9
5 2 1 5 2 1 5 2 1
4
1 2 3 4
0

8 3 8 15 2 11 4 8 1
*/

void print_array(int* array, int length){
    for (int i = 0; i < length; i++){
        cout << array[i] << " ";
    }
    cout << "\n";
}
bool get_possible_combination(int* sticks, int* occupied, int length, int aim, int remain, int aim_all, int start){
    if(remain == 1){
        if(sticks[start] == aim){

            /*printf("START = AIM Occupied: ");
            print_array(occupied, length);
            printf("remain = %d\n", remain);
            printf("start = %d\n", start);*/
            return true;
        }
        else return false;
    }else{
        if (aim == aim_all){
            occupied[start] = 1;
            int aim_p = aim - sticks[start];
            if (aim_p == 0) aim_p = aim_all;
            remain --;
            /*cout <<"aim_p = " << aim_p << " start = " << start << endl;
            printf("Occupied: ");
            print_array(occupied, length);
            printf("remain = %d\n", remain);*/
            int n_start = -1;
            for (int k = 0; k < length; k++){
                if (occupied[k] == 0){
                    n_start = k;
                    break;
                }
            }
            bool res = get_possible_combination(sticks, occupied, length, aim_p, remain, aim_all, n_start);
            occupied[start] = 0;
            remain++;
            /*cout <<"aim_p = " << aim_p << " AFTER start = " << start << endl;
            printf("Occupied: ");
            print_array(occupied, length);
            printf("remain = %d\n", remain);*/
            return res;
        }
        bool res = false;
        int s_p = -1;
        for (int i = start; i < length; i++){
            if (occupied[i] == 0 && sticks[i] <= aim){
                s_p = i;
                break;
            }
        }
        if (s_p < 0){
            return false;
        }
        int i = s_p;
        while(i < length){
            if (occupied[i] == 1) {i++; continue;}
            int aim_p = aim - sticks[i];
            occupied[i] = 1;
            remain --;
            /*cout << "BEFORE aim_p = " << aim_p << " i = " << i << endl;
            printf("Occupied: ");
            print_array(occupied, length);
            printf("remain = %d\n", remain);*/
            if (aim_p == 0) {
                //cout << "start = " << start << endl;
                for (int k = 0; k < length; k++){
                    if (occupied[k] == 0){
                        start = k;
                        break;
                    }
                }
                res = get_possible_combination(sticks, occupied, length, aim_all, remain, aim_all, start);
                if (!res){
                    occupied[i] = 0;
                    remain ++;
                    /*cout << "AFTER " << " i = " << i << endl;
                    printf("Occupied: ");
                    print_array(occupied, length);
                    printf("remain = %d\n", remain);*/
                }
                break;
            }else{
                for (int k = i; k < length; k++){
                    if (occupied[k] == 0){
                        start = k;
                        break;
                    }
                }
                if (get_possible_combination(sticks, occupied, length, aim_p, remain, aim_all, start)){
                    res = true;
                    break;
                }
            }

            occupied[i] = 0;
            remain ++;

            /*cout << "AFTER " <<" i = " << i << endl;
            printf("Occupied: ");
            print_array(occupied, length);
            printf("remain = %d\n", remain);*/
            int move = 0;
            for (int k = i; k < length; k++){
                if (sticks[k] == sticks[i]){
                    move++;
                }
            }
            i += move;
        }
        return res;
    }

}

int cmpfunc(const void* a, const void* b){
    return *(int*)b - *(int*)a;
}
int main(){
    int length;
    while(cin >> length && length != 0){
        int* sticks = new int[length];
        int* occupied = new int[length];
        int max_len = 0;
        int sum = 0;
        for (int i = 0; i < length; i++){
            cin >> sticks[i];
            occupied[i] = 0;
            if (sticks[i] > max_len) max_len = sticks[i];
            sum += sticks[i];
        }
        qsort(sticks, length, sizeof(int), cmpfunc);

        /*for (int i = 0; i < length; i++){
            cout << sticks[i] << " ";
            occupied[i] = 0;
        }
        cout << endl;
        cout << max_len << " " << sum << endl;*/
        if (sum == max_len){cout << sum << endl;}
        else{
            for (int len = max_len; len <= sum; len++){
                //cout << "len = " << len << endl;
                int remain = length;
                if (sum % len != 0) continue;
                if (get_possible_combination(sticks, occupied, length, len, remain, len, 0)){
                    cout << len << endl;
                    break;
                }
            }
        }
        }

    return 0;
}
