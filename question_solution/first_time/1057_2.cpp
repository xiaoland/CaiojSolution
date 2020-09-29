// author: Lan_zhijiang
// description: 含价值的填满型背包1
// 一维数组版
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
        for(int j = ml; j>=v[i]; j--) {
            
            if(out[j-v[i]] != -1) {
                out[j] = max(out[j], out[j - v[i]] + m[i]);
            }
        }
    }
    int maxv = 0;
    for(int i = 1; i<=ml; i++) {  // 找最大值
        maxv = max(maxv, out[i]);
    }
    printf("%d\n", maxv);
    return 0;
}