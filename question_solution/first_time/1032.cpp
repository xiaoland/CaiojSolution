#include <cstdio>
using namespace std;
int a[110], v[110];
int n, r;

void dfs(int k) {

    if (k > r) {
        // print
        for(int i = 1; i <= r; i++) {
            printf("%d", a[i]);
            if (i == r) {
                printf("\n");
            }
            else {
                printf(" ");
            }
        }
    }
    else {
        // continue
        for(int i = a[k-1]+1; i <= n; i++) {
            if (v[i] == 0) {
                v[i] = 1;
                a[k] = i;
                dfs(k+1);
                v[i] = 0;         
            }
        }
    }

}


int main() {

    scanf("%d%d", &n, &r);

    for(int i = 1; i <= n; i++) {
        v[i] = 0;
    }
    a[0] = 0;
    dfs(1);
    return 0;

}