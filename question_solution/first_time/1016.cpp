#include <cstdio>
using namespace std;
int pd(int x) {

    int x1, x2, x3, x4;
    x1 = x%10;
    x2 = x/10%10;
    x3 = x/100%10;
    x4 = x/1000;
    if(x1 == x4 && x2 == x3) {
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