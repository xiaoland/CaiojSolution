#include <cstdio>
#include <cstring>
using namespace std;
int n;
int out[4400];

void dfs(int k, int s) {

    if (s == n) {
        // print
        for(int i = 1; i < k; i++) {
            printf("%d", out[i]);
            if (i == k-1) {
                printf("\n");
            }
            else {
                printf("+");
            }
        }
    }
    else if (s > n) {
        // return back
    }
    else {
        // generate
        for(int i = 1; i <= n; i++) {
            out[k] = i;
            s+=i;
            dfs(k+1, s);
        }
    }

}

int main() {

    scanf("%d", &n);
    memset(out, 0, sizeof(out));
    dfs(1, 0);
    return 0;
    
}