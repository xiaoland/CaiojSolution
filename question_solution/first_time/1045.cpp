#include <cstdio>
#include <algorithm>
using namespace std;

double dfs(double x, double y, int k) {
    if(k == 1) { // 已经切到最小一块了，返回比值
        return max(x, y)/min(x, y);  // KNOWLEDGE POINT: 超有用！
    }
    double ans = 999999.0;
    // i<k: 要切k块，只需要k-1刀
    for(int i = 1;i<k;i++) {
        ans = min(ans, max(dfs(x, y/k*i, i), dfs(x, y/k*(k-i), k-i))); // max_param1: 就平均分k块  max_param2: 切了再切，切到最小
    }
    for(int i = 1;i<k;i++) {
        ans = min(ans, max(dfs(x/k*i, y, i), dfs(x/k*(k-i), y, k-i)));
    }
    return ans;
}

int main() {
    double x, y, k;
    scanf("%lf%lf%lf", &x, &y, &k);
    printf("%.6lf", dfs(x, y, k));
}