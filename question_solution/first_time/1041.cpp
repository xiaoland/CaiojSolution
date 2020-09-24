// x: 第几个村庄的路程数据
// i(dfs else): 该第x个村庄到第i个村庄的路程
// sum: 路程累计
#include <cstdio>
#include <cstring>
using namespace std;
int n, a[20][20];
int ans;
bool v[20];

void dfs(int x, int k, int sum) {
    if(k>n) {
        if(sum+a[x][1]<ans) { // 因为else的i从2开始，1是加不到的，所以在这里加
            ans = sum+a[x][1];
        }
    }
    else {
        for(int i = 2;i<=n;i++) {
            if(v[i]) {
                if (sum+a[x][i]>=ans) { // 如果已经大于上一次的路径数据了，就退出，防止超时
                    return ;
                }
                v[i] = false;
                dfs(i, k+1, sum+a[x][i]); // [x][i]就是从x村到i村的路程大小，相当于到达了i村，所以i村要作为下一个的x村继续
                v[i] = true;
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 1;i<=n;i++) {
        for(int j =1;j<=n;j++) {
            scanf("%d", &a[i][j]);
        }
    }
    memset(v, true, sizeof(v));
    ans = 9999999;
    dfs(1, 2, 0);
    printf("%d\n", ans);
}