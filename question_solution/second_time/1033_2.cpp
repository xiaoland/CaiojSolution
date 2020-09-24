// 组合+判断素数：输出每个n个数中由r个数 组成的组合 的和 为素数 的数量
#include <cstdio>
#include <cstring>
int n, r, ans;
int nr[110], a[110], v[110];

bool pd(int x) {
    for(int i = 2; i*i<=x; i++) {  // ATTENTION: i*i和sqrt(x)都是要<=x的
        if(x%i == 0) {
            return false;
        }
    }
    return true;
}

void dfs(int k) {
    if(k > r) {
        int s = 0;
        for(int i = 1; i<=r; i++) {
            s+=nr[a[i]];
        }
        if(pd(s)) {
            ans++;
            // for(int i = 1; i<r; i++) {
            //     printf("%d ", a[i]);
            // }
            // printf("%d\n", a[r]);
        }
    }
    else {
        for(int i = a[k-1]+1;i<=n;i++) {   // ATTENTION: 只要是在n个数中选r个数，都不可以少了a[k-1]+1
            if(v[i] == 0) {
                v[i] == 1;
                a[k] = i;
                dfs(k+1);
                v[i] = 0;
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &r);
    for(int i = 1; i<= n;i++) {
        scanf("%d", &nr[i]);
    }
    ans = 0;
    memset(v, 0, sizeof(v));
    a[0] = 0; // ATTENTION: 只要是在n个数中选r个数，都不可以少了这个
    dfs(1);
    printf("%d", ans);
}