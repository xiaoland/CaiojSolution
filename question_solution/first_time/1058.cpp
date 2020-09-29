// author: Lan_zhijiang
// description: 含价值的填满型 完全 背包
// 本题的关键在于宝石数量无限
// 需要进一步动态输出理解(需先理解1057_2)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int ml, n, m[101], v[101];
int out[10001];

void read_in() {
    scanf("%d%d", &ml, &n);
    for(int i = 1; i<=n; i++) {
        scanf("%d%d", &v[i], &m[i]);
    }
}

int main() {
    read_in();

    memset(out, -1, sizeof(out));
    out[0] = 0;

    for(int i = 1; i<=n; i++) {
        for(int j = v[i]; j<=ml; j++) {
            if (out[j - v[i]] != -1) {
                out[j] = max(out[j], out[j - v[i]] + m[i]);
            }
        }
    }

    int maxv = 0;
    for(int i = 1; i<=ml; i++) {
        maxv = max(maxv, out[i]);
    }
    printf("%d\n", maxv);
    return 0;
}