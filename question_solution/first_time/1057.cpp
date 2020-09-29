// author: Lan_zhijiang
// description: 含价值的填满型背包1
// 二维数组版
// 背包问题就是要你作出在限制条件下的最佳组合选择
// 解决背包问题最朴素的方法就是列出所有可能性
// 但根据题目条件的不同，都有不同的优化
// 我们还要特别注意节省内存，将自己的算法进行简化，找出多余的部分（比如将二维数组转为一维数组来使用）
// 要检查草稿有没有错误，按着你写的代码再来自己执行一遍，不要弄错了
#include <cstdio>
#include <cstring>
#include <algorithm>  // 背包问题要用的max
using namespace std;  // algotithm不可少

int n, m[101], t[101], tl;
int out[101][1001];

void read_in() {
    scanf("%d%d", &tl, &n);
    for(int i = 1; i<=n; i++) {
        scanf("%d%d", &t[i], &m[i]);
    }
}

int main() {
    read_in();

    for(int i = 1; i<=n; i++) {  // 将时间=0或宝石=0的地方都填上0（任何一个为0都没意义）
        out[i][0] = 0;
    }
    for(int i = 1; i<=tl; i++) {
        out[0][i] = 0;
    }

    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=tl; j++) {
            if(j<t[i]) {
                out[i][j] = out[i-1][j];
            }
            else {
                out[i][j] = max(out[i-1][j], out[i-1][j - t[i]]+m[i]);
            }
        }
    }

    printf("%d\n", out[n][tl]);

    return 0;
    
}
