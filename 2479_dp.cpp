#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    /*cin can be slow because it needs to sync with C IO
    disable the sync here to make iostream fastest
    */
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        int length;
        scanf("%d", &length);
        int* num = new int[length];
        /*
        int* dp1 = new int[length];
        int* dp2 = new int[length];
        int dp_pre;
        for(int k = 0; k < length; k++){
            scanf("%d", &num[k]);
            if (k == 0){
                dp1[k] = num[k];
                dp_pre = num[k];
            }
            else{
                dp_pre = max(dp_pre + num[k], num[k]);
                dp1[k] = max(dp1[k - 1], dp_pre);
            }
        }
        dp2[length - 1] = 0;
        for(int k = 1; k < length; k++){
            if (k == 1){
                dp2[length -1 - k] = num[length - k];
                dp_pre = num[length - k];
            }
            else{
                dp_pre = max(num[length - k], dp_pre + num[length - k]);
                dp2[length - 1 - k] = max(dp2[length - k], dp_pre);
            }
        }
        int res = dp1[0] + dp2[0];
        for(int k = 1; k < length - 1; k++){
            if (dp1[k] + dp2[k] > res){
                res = dp1[k] + dp2[k];
            }
        }
        printf("%d\n", res);
        */
        int* dp1 = new int[length];
        int dp2;
        int dp_pre;
        for(int k = 0; k < length; k++){
            scanf("%d", &num[k]);
            if (k == 0){
                dp1[k] = num[k];
                dp_pre = num[k];
            }
            else{
                dp_pre = max(dp_pre + num[k], num[k]);
                dp1[k] = max(dp1[k - 1], dp_pre);
            }
        }
        int res;
        for(int k = 1; k < length; k++){
            if (k == 1){
                dp2 = num[length - k];
                dp_pre = num[length - k];
                res = dp2 + dp1[length - k - 1];
            }
            else{
                dp_pre = max(num[length - k], dp_pre + num[length - k]);
                dp2 = max(dp2, dp_pre);
                if (dp2 + dp1[length - k - 1] > res){
                    res = dp2 + dp1[length - k - 1];
                }
            }
        }
        printf("%d\n", res);
    }

}
