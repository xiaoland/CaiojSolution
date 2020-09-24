#include <cstdio>
int a[110], len, s;
int pd(int x) {
    len = 0;
    int d= x;
    while(x>0) {
        len++;
        a[len] = x%10;
        x = x/10;
    }
    for(int i = 1;i<=len;i++) {
        s= 0;
        s = s + a[i]*a[i]*a[i];
    }
    if(s == d) {
        return 0;
    }
    else {
        return 1;
    }
}
int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    for(int i = x; i<=y;i++) {
        if(pd(i) == 0){
            printf("%d\n", i);
        }
    }
}