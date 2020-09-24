#include <cstdio>
#include <cstring>
#include <cmath>
int n, a[20], v[20];
int mp[20][20];

bool spd(int c) {
    int t = int(sqrt(double(c+1)));
    for(int i = 2;i<=t;t++) { // ATTENTION： 判断素数永远从2开始
        if(c%i == 0) {
            return false;
        }
    }
    return true;
}

void dfs(int k) {
    if(k>n) {
        //print
        if(mp[a[1]][a[n]] == 0) { // 注意mp中要放入对应的数字，而不是序号
            for(int i = 1;i<n;i++) {
                printf("%d ", a[i]);
            }
            printf("%d\n", a[n]);
        }
    }
    else {
        // continue
        for(int i = 2;i<=n;i++) {
            if(v[i] == 0&&mp[a[k-1]][i] == 0) {
                v[i] = 1;
                a[k] = i;
                dfs(k+1);
                v[i] = 0;
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    memset(mp, 0, sizeof(mp));
    for(int i = 1;i<=n;i++) {
        for(int j = i+1;j<=n;j++) {
            if(spd(i+j) == false) {
                mp[i][j] = 1;
                mp[j][i] = 1;
            }
        }
    }
    memset(v, 0, sizeof(v));
    v[1] = 1;
    a[1] = 1;
    dfs(2);
}