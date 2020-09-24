//TIME COUNT: 1:32 PASS: 3
#include <cstdio>
using namespace std;
int f(int a, int b) {
    int c, lc;
    c = a%b;
    for (int i = 0; i>= 0; i++) {
        if(c == 0) {
            return lc;
        }
        lc =c;
        if(i == 0) {
            c = b%c;
        }
        else {
            c = lc%c;
        }
    }
}
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d", f(a, b));
}