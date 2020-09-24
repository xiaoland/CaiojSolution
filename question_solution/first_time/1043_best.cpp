#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int n;
int v[11110000];

int dfs(int x) {
    if(x == 1) {
        return 1;
    }
    if(x<=10000000&&v[x] != 0) {  // 如果这个因子已经分解过了，那就直接返回上次的结果
        return v[x];
    }
    int t = int(sqrt(double(x+1))), ans = 1; // 不要让ans进行累加，ans只是这次分解的
    for(int i = 2;i<=t;i++) {
        if(x%i == 0) {
            ans+=dfs(i) + dfs(x/i); // 因子和另一个因子都继续分解
        }
    }
    if(t*t == x) {
        ans-=dfs(t); // 防止像9=3*3这样的数重复加入
    }
    if(x<=1000000) {
        v[x] = ans; // 这一次分解的结果记录下来，防止同样因子再次分解
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    memset(v, 0, sizeof(v));
    printf("%d\n", dfs(n));
}