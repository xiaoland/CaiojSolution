#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std; // algorithm不能没有这个
double X, Y, N;

double dfs(double x, double y, int k) {
    if(k == 1) { // k-i = 1结束 or i=1结束
        return max(x, y)/min(x, y);  // 返回比例（最终结果）
    }
    double ans = 999999.0; // 每一次都要重置
    for(int i = 1; i<k; i++) {  // 竖着切
        ans = min(ans, max(dfs(x, y/k*i, i), dfs(x, y/k*(k-i), k-i)));
    }
    for(int i = 1; i<k; i++) {  // 横着切
        ans = min(ans, max(dfs(x/k*i, y, i), dfs(x/k*(k-i), y, k-i)));
    }
    return ans;
}

int main() {
    scanf("%lf%lf%lf", &X, &Y, &N); // 说是输入为整数，但是读入的时候还是得用float
    printf("%.6lf", dfs(X, Y, N));
}