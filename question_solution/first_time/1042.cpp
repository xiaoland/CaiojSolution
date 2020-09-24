#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int n, m, ans = 0;
int a[200];
bool v[200];

void dfs(int k, int d, int last) {
    if(ans==m) {
        return ;
    }
    if(abs(d-m)<abs(ans-m)){
        ans = d;
    }
    if(k>n) {
        return ;
    }
    else {
        for(int i = last+1;i<=n;i++) {
            if(v[i]) {
                if (i+d<=m||abs(ans-m)>abs(d-m)){ // 反言之，就是在说：如果？？？确定这不是个BUG？？？
                    v[i] = false;
                    dfs(k++, d+a[i], i);
                    v[i] = true;
                }
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1;i<=n;i++) {
        scanf("%d", &a[i]);
    }
    memset(v, true, sizeof(v));
    dfs(1, 0, 0);
    printf("%d\n", ans);
}