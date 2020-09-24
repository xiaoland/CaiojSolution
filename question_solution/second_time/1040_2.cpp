#include <cstdio>
#include <cstring>
int n, a[110], va[110];
bool v[110][110]; // 不要把这个放到int里啦！

bool pd(int x) {
    for(int i = 2; i*i<=x; i++) {  // 小心不要打成i*i<=n了
        if(x%i == 0) {
            return false;
        }
    }
    return true;
}

void dfs(int k) {
    if(k > n) {
        // print
        if(v[a[1]][a[n]]) {
            for(int i = 1; i<n; i++) {
                printf("%d ", a[i]);
            }
            printf("%d\n", a[n]);
        }
    }
    else {
        // continue
        for(int i = 2; i<=n; i++) {
            if(va[i] == 0 && v[a[k-1]][i]) { // ATTENTION：a->k，不是i，还有v的第二维是i，不是a[k]，a[k]还没写入呢！；而在这里验证，更快速
                va[i] = 1;
                a[k] = i;
                dfs(k+1);
                va[i] = 0;
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    memset(va, 0, sizeof(va));
    memset(v, true, sizeof(v));
    for(int i = 1; i<=n; i++) {
        for(int j = i+1; j<=n; j++) {
            if(pd(i+j) == false) {
                v[i][j] = v[j][i] = false;
            }
        }
    }
    va[1] = 1;  // 因为其要求从1开始逆时针排序，所以第一个永远是1，上面的i也因此从2开始
    a[1] = 1;  // 而且为了避免k-1出现错误，要在这里填上
    dfs(2);
}