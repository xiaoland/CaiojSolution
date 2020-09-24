#include <cstdio>
#include <cstring>
using namespace std;
int n, target_arr[16], target_k, k_result[16];
int arr_len = 1, a[16], v[16];
struct node {
    int arrment[16];
}all_arr[11100];

void generate_arr(int k) {
    if(k > n) {
        for(int i = 1; i <=n; i++) {
            all_arr[arr_len].arrment[i] = a[i];
        }
    }
    else {
        for(int i = 1; i<= n; i++) {
            if(v[i] == 0) {
                v[i] = 1;
                a[k] = i;
                generate_arr(k+1);
                v[i] = 0;
                a[k] = 0;
            }
        }
    }
}

int get_factorial(int x) {
    int result = 1;
    for(int i = 2; i<=x; i++) {
        result = result*i;
    }
    return result;
}

int inverse_opreation_cantor(int x, int len) { // ERROR!
    int ans[len+1], bf = x-1, appear[len+1], nac;
    
    memset(appear, 0, sizeof(appear));

    for(int i = 1; i<= len; i++) {
        nac = bf / get_factorial(len-i);
        bf = bf-nac*get_factorial(len-i);
        
        int j;
        for(j = 1; j<=len; j++) {
            if(appear[j] == 0) {
                if(nac == 0) {
                    break;
                }
                nac-=1; // ATTENTION: 不要打成nac-1了
            }
        }
        appear[j] = 1;  // 不在里面！！j在外边定义！
        // k_result[i] = j;
        ans[i] = j;
    }
    return ans[len+1];
}

int cantor(int target[16], int len) {  // ATTENTION: read in a array, target[16]
    int ans = 0, appear[len+1];
    // printf("CANTOR COMPUTE START: target_len: %d\n", len);  // FOR DEBUG
    memset(appear, 0, sizeof(appear));

    for(int i = 1; i<=len; i++) {
        int not_appear_count = 0;
        appear[target[i]] = 1;
        for(int j = 1; j<target[i]; j++) {  // ATTENTION: j<target[16]
            if(appear[j] == 0) {  // ATTENTION: appear->j
                not_appear_count++;
            }
        }
        ans = ans+not_appear_count*get_factorial(len-i);
        // printf("index: %d, nn: %d, nac: %d, ans: %d\n", i, target[i], not_appear_count, ans); // FOR DEBUG
    }
    return ans+1;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i<= n; i++) {
        scanf("%d", &target_arr[i]);
    }
    scanf("%d", &target_k);

    generate_arr(1);
    printf("TARGET ARR INDEX: %d\n", cantor(target_arr, n));

    k_result[n+1] = inverse_opreation_cantor(target_k, n);
    printf("TARGET K RESULT: ");
    for(int i = 1; i<n; i++) {
        printf("%d ", k_result[i]);
    }
    printf("%d\n", k_result[n]);
}