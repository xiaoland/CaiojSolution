// author: Lan_zhijiang
// description: the solution of problem 1065

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, stay = 0;
int ha[110];
int las[110];
int lds[110];

void build_las() {
    
    for (int i = 1; i<=n; i++) { // ???为什么这里不能用memset???
        las[i] = 1;
    }

    for (int i = 2; i<=n; i++) {
        for (int j = i-1; j>=1; j--) {
            if (ha[j] < ha[i]) {
                las[i] = max(las[i], las[j]+1);
            }
        }
    }
}
// 最长上升子序列 和 最长下降子序列 只是方向不同，依旧是运行方向大于初始方向
void build_lds() {
    
    for (int i = 1; i<=n; i++) {  // ???为什么这里不能用memset???
        lds[i] = 1;
    }

    for (int i = n-1; i>=1; i--) {
        for (int j = i+1; j<=n; j++) {
            if (ha[j] < ha[i]) {
                lds[i] = max(lds[i], lds[j]+1);
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i<=n; i++) {
        scanf("%d", &ha[i]);
    }

    build_las();
    build_lds();
    
    // 出列最少=留下最多
    for (int i = 1; i<=n; i++) {
        stay = max(las[i] + lds[i]-1, stay);
    }
    printf("%d\n", n-stay);
    return 0;
}

