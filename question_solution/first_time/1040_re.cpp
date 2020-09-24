#include <cstdio>
#include <cstring>
#include <cmath>
int a[20], n;
bool mp[20][20], v[20];

bool pd(int c) {
    int t = int(sqrt(double(c+1)));
    for(int i = 2;i<=t;i++) {
        if(c%i == 0) {
            return false;
        }
    }
    return true;
}

void dfs(int k) {
    if(k>n) {
        if(mp[a[1]][a[n]]) {
            for(int i = 1;i<n;i++) {
                printf("%d ", a[i]);
            }
            printf("%d\n", a[n]);
        }
    }
    else {
        for(int i = 2;i<=n;i++) {
            if(v[i] == true&&mp[a[k-1]][i] == true) {
                v[i] = false;
                a[k] = i;
                dfs(k+1);
                v[i] = true;
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    memset(mp, true, sizeof(mp));
    for(int i = 1;i<=n;i++) {
        for(int j = i+1;j<=n;j++) {
            if(pd(i+j) == false) {
                mp[i][j] = mp[j][i] = false;
            }
        }
    }
    memset(v, true, sizeof(v));
    v[1] = false;
    a[1] = 1;
    dfs(2);
}