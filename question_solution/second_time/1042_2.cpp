#include <cstdio>
#include <cstring>
#include <cmath>
int n, m, a[110], v[110];
int ans = 99999;

void dfs(int d, int last, int k) {
    if(ans == m) {
        return ;
    }
    if(abs(ans-m)>abs(d-m)) {
        ans = d;
    }
    if(k > n) {
        return ;
    }
    else {
        for(int i = last+1; i<=n; i++) {
            if(v[i] == 0) {
                if(abs(ans-m)>abs(d-m) || i+d<=m) {
                    v[i] = 1;
                    dfs(d+a[i], i, k+1);
                    v[i] = 0;
                }
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i<= n; i++) {
        scanf("%d", &a[i]);
    }
    memset(v, 0, sizeof(v));
    dfs(0, 0, 1);
    printf("%d\n", ans);
}