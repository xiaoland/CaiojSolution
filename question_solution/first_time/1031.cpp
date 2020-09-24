#include <cstdio>
using namespace std;
int n;
int oa[110], v[110];

void fn(int a) {

    // if (a > n) {

    // }
    // else {
    //     for(int i = 1; i <= n; i++) {
    //         if (v[i] == 0) {
    //             v[i] = 1;
    //             printf("%d", i);
    //             if (i < n) {
    //                 printf(" ");
    //             }
    //             else if (i == n) {
    //                 printf("\n");
    //             }
    //             fn(a+1);
    //             v[i] = 0;
    //         }
    //     }
    // }
    
    if (a==n+1) {
        // row generated, start print...
        for(int i = 1; i <= n; i++) {
            if (i == n) {
                printf("%d\n", oa[i]);
            }
            else {
                printf("%d ", oa[i]);
            }
        }
    }
    else {
        // continue generate the arrangement...
        for(int k = 1; k <= n; k++) {
            if (v[k] == 0) {
                v[k] = 1;
                oa[a] = k;
                fn(a+1);
                oa[a] = 0;
                v[k] = 0;
            }
        }
    }

}


int main() {

    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        v[i] = 0;
    }
    fn(1);

}
