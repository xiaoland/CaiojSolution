// author: Lan_zhijiang
// description: the solution of problem 1066
// 求什么，f数组就记录什么，一切遍历等操作都为了填写f而服务
// 如：求时间的最小值，那么通过计算出所有情况下的时间，记录在f中，最后输出的时候找到符合条件的就好了

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

double bw, length;
int n;
double sa[1001], wa[1001];
double f[1001];

void read_in() {
    wa[0] = 0.0;

    scanf("%lf%lf%d", &bw, &length, &n);
    for (int i = 1; i<=n; i++) {
        scanf("%lf%lf", &wa[i], &sa[i]);
        sa[i]/=60.0000;
        wa[i]+=wa[i-1];
    }
}

int main() {
    read_in();

    f[0] = 0.0;

    for (int i = 1; i<=n; i++) {
        f[i] = f[i-1] + length/sa[i];

        double mins = sa[i];
        for (int j = i-1; j>=1; j--) {
            if (wa[i] + wa[j-1] > bw) {  // ???
                break;
            }
            else {
                mins = min(mins, sa[j]);
                f[i] = min(f[i], f[j-1] + length/mins);
            }
        }
    }

    printf("%.1lf\n", f[n]);
    return 0;
}
