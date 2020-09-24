// x: 累计质量
// abs(ans-m): 目前最优解与目标的差
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int ans=999999999, a[201];
int n, m;

void dfs(int x, int y) {
    if(abs(m-x) < abs(ans-m)) { // 如果目前解的差已经比最优解要好了，那就更新
        ans = x;
    }
    if(x >= m + abs(ans-m)) { // 如果累计质量已经超过或等于最优解差+m的范围，那就没必要继续了
        return ;
    }
    for(int i = y; i<=n; i++) { // 直接从last(y)开始，因为每个石头只能用一次
        dfs(x+a[i], i+1);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i<=n; i++) {
        scanf("%d", &a[i]);
    }
    dfs(0, 1);
    printf("%d\n", ans);
    return  0;
}