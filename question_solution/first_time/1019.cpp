#include <cstdio>
using namespace std;

void build_yanghui_trigle(int n) {

    int yht_arr[n][n+1];

    for(int i = 0; i < n; i++) {

        yht_arr[i][0] = 1;
        yht_arr[i][i] = 1;

    }    

    for(int i = 0; i < n; i++) {

        int wait_number_count = i + 1 - 2;
        if (wait_number_count <= 0) {
            continue;
        }
        else {
            for(int a = 1; a <= wait_number_count; a++) {
                yht_arr[i][a] = yht_arr[i-1][a-1] + yht_arr[i-1][a];
            }
        }
    
    }

    for(int i = 0; i < n; i++) {
        for(int a = 0; a < n; a++) {
            int output = yht_arr[i][a];
            if (output == 0) {
                continue;
            }
            else {
                if (a == i+1) {
                printf("%d\n", yht_arr[i][a]);
            }
            else {
                printf("%d  ", yht_arr[i][a]);
            }
            }
        }
    }

}

int main() {

    int n;
    scanf("%d", &n);
    build_yanghui_trigle(n);
    return 0;
}
