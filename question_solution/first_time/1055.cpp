// author: Lan_zhijiang
// description: 填满型背包1
#include <cstdio>
#include <cstring>

bool v[20001];
int r, a[31], n;

int main() {
    scanf("%d", &r);
    scanf("%d", &n);
    for(int i = 1; i<=n; i++) {
        scanf("%d", &a[i]);
    }

    memset(v, false, sizeof(v));
    v[0] = true;
    int s;

    for(int i = 1; i<=n; i++) {
        for(int j = r; j>=a[i]; j--) { // 只要问到它自己就好了（倒序）
            if(v[j] == false) {
                v[j] = v[j-a[i]];  // a->i; f/v->j
            }
        }
    }

    int x = r;
    while(v[x] == false) {
        x--;
    }

    printf("%d\n", r-x);
    return 0;
}