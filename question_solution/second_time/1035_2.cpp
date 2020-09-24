// n皇后问题：主要是要判断 列 行 左斜 右斜 上有没有皇后的问题，输出所有方案的皇后所在列号
#include <cstdio>
#include <cstring>
using namespace std;
int x[110], y[110], l[230], r[230];
int a[110];
int n;

void dfs(int k) {
    if(k > n) {
        for(int i = 1;i<n;i++) {
            printf("%d ", a[i]);
        }
        printf("%d\n", a[n]);
    }
    else {
        for(int j = 1;j<=n;j++) {
            if(x[k] == 0 && y[j] == 0 && l[j-k+1] == 0 && r[j+k-n] == 0) { // x->k y->j  l->j-k+1 r->j+k-n
                x[k] = 1;y[j] = 1;
                l[j-k+1] = 1;r[j+k-n] = 1;
                a[k] = j;
                dfs(k+1);
                x[k] = 0;y[j] = 0;
                l[j-k+1] = 0;r[j+k-n] = 0;
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    dfs(1);
}