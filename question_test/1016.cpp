// TIME COUNT: 1:33 PASS: 1
#include <cstdio>
using namespace std;
int pd(int a) {

    int a1, a2, a3, a4;
    a1 = a%10;
    a2 = a/10%10;
    a3 = a/100%10;
    a4 = a/1000;
    if(a1 == a4 && a2 == a3) {
        return 0;
    }
    else {
        return 1;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    if(pd(n) == 0) {
        printf("YES");
    }
    else {
        printf("NO");
    }
}