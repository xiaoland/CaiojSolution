#include <cstdio>
using namespace std;
int n, r, ans;
int a[110], v[110], x[22];


int iss(int s) {
    // pd su shu
    for(int i = 2; i*i <= s; i++) {
        if (s%i == 0) {
            return 1;
        }
    }
    return 0;
}

void dfs(int k) {

    if (k > r) {
        // print
        int s = 0;
        for(int i = 1; i <= r; i++) {
            s = s + x[a[i]];
        }
        if (iss(s) == 0) {
            ans++;
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
        scanf("%d", &x[i]);
        v[i] = 0;
    }
    a[0] = 0;
    dfs(1);
    printf("%d", ans);
    return 0;

}

