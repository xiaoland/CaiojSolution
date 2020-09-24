#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm> // algo ri thm
using namespace std; // 在这里，这个绝对不能少！！！
int a[1100];
int n, len, ans;

void yzf(int x) {
    // int t = sqrt(x);
    for(int i = 2;i*i<=x;i++) {
        if(x%i == 0) {
            a[++len] = i;  // 变量前++等前缀是指：在调用前先自加
            if(i*i != x) {  // 因子找到一个就可以用除法找到另一个，但是为了避免像9=3*3这样的重复相加出现，在这里添加一个判断
                a[++len] = x/i;
            }
        }
    }
}

void dfs(int x) {
    if(x == 1) {  // 如果已经被除到1了，代表这个方案可行，就++
        ans++;
    }
    else {
        for(int i = 1;i<=len;i++) {  // 是在因子总数的范围内循环，不是n
            if(x<a[i]) {  // 如果被除数比除数小，那么这就是个分数，所以没有意义，直接break(不是return！)
                break;
            }
            if(x%a[i] == 0) {
                dfs(x/a[i]);
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    ans = 1; // n=n这也是一个方案
    len = 0;
    yzf(n);
    sort(a+1, a+len+1);  // param1: 数组的「首」地址; param2: 数组的「尾」地址的「下一」地址
    dfs(n);
    printf("%d\n", ans);
}