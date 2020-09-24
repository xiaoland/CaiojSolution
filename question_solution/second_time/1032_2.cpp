// 组合：从1-n中选r个数按照字典序输出所有排列
#include <cstdio>
#include <cstring>
int n, r, a[110], v[110];

void dfs(int k) {
    if(k > r) {
        for(int i = 1; i<r;i++) {
            printf("%d ", a[i]);
        }
        printf("%d\n", a[r]);
    }
    else {
        for(int i = a[k-1]+1; i<= n;i++) {  // ATTENTION: 从上一个数+1开始，全排列则从1开始
            if(v[i] == 0) {
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
    memset(v, 0, sizeof(v));
    a[0] = 0;
    dfs(1);
}