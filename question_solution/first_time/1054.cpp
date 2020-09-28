#include <cstdio>
#include <cstring>
struct num {
    int a[1100];
    int len;
    num() {
        len = 0;
        memset(a, 0, sizeof(a));
    }
};
num a;
int n;
char as[1100];

int main() {
    scanf("%d", &n);
    scanf("%s", as+1);
    a.len = strlen(as+1);

    for(int i = 1; i<=a.len; i++) {
        a.a[a.len+i-1] = as[i] - '0';
    }

    num c = multiply_x(a, n);

    for(int i = c.len; i>=1; i--) {
        printf("%d", c.a[i]);
    }
    printf("\n");
    return 0;
}