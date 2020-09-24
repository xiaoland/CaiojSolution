// TIME COUNT: 1:35 PASS: 1
#include <cstdio>
using namespace std;
int main() {
    int a, b, c, x, y;
    scanf("%d%d", &x, &y);
    for(int i = x; i<=y;i++) {
        a = i%10;
        b = i/10%10;
        c = i/100;
        if(a*a*a+b*b*b+c*c*c == i) {
            printf("%d\n", i);
        }
    }
}