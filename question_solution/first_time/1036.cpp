#include <cstdio>
int n, s;

void dg(int a, int b, int c) {

    if(c >= n) {
        s++;
        return ; 
    }                      // ATTENTION: use if! not else if!
    if (a > 0 && b < n) {
        dg(a-1, b+1, c);
    }
    if (b > 0 && c < n) {
        dg(a, b-1, c+1);
    }

}


int main() {

    scanf("%d", &n);
    s = 0;
    dg(n, 0, 0);
    printf("%d", s);
    return 0;

}
