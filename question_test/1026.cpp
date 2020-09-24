// TIME COUNT: 1:39 PASS: 3
#include <cstdio>
int a[110], len;
int pd(int x) {
    len = 0;
    while(x>0) {
        len++;
        a[len] = x%10;
        x = x/10;
    }
    for(int i = 1; i<=len/2;i++) {
        if(a[i] != a[len-i+1]) {
            return 1;
        }
    }
    return 0;
}
int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    for(int i = x;i<=y;i++) {
        if(pd(i) == 0) {
            printf("%d\n", i);
        }
    }
}