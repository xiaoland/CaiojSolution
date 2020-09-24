#include <cstdio>
#include <cstring>
int n, a[110][110], v[110];
int ans;
 
void dfs(int x, int k, int sum) {
    if(k > n) {
        if(sum+a[x][1]<ans) {  // 售货员还要返回村庄 
            ans = sum+a[x][1];
        }
    }
    else {
        for(int i = 2; i <= n; i++) {
            if(v[i] == 0) {
                if(sum+a[x][i] >= ans) {  // 剪枝，否则会超时 
                    return ;
                }
                v[i] = 1;
                dfs(i, k+1, sum+a[x][i]);
                v[i] = 0;
            }
        }
    }
}
 
int main() {
    scanf("%d", &n);
    for(int i = 1; i<= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    memset(v, 0, sizeof(v));
    ans = 999999;
    dfs(1, 2, 0);
    printf("%d\n", ans);
}