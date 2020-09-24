// TIME COUNT: 1:31 PASS: 2
#include <cstdio>
#include <cmath>
int main() {
    int A, B, c;
    scanf("%d%d", &A, &B);
    for(int a = A;a<=B;a++) {
        for(int b = a;b<=B;b++) {
            int cc = a*a+b*b;
            c = sqrt(cc);
            if(c*c == cc&&c<=B){
                printf("%d %d %d\n", a, b, c);
            } 
        }
    }
}