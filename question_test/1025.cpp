// TIME COUNT: 1:13 PASS: 2
#include <cstdio>
using namespace std;
int main() {
    int a, b, x ,s;
    scanf("%d%d", &a, &b);
    for(int i = a;i<=b;i++) {
        x = i;
        s = x*x;
        int d = 1;
        while(d<=x){
            d*=10;
        }
        if(s%d == x) {
            printf("%d\n", i);
        }
    }
}