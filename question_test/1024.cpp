// TIME COUNT: 2:23 PASS: 4

#include <cstdio>
#include <cmath>
using namespace std;
int main() {
	int x, y, a, b , sa, sb;
	scanf("%d%d", &x, &y);
	for(a=x; a<=y;a++) {
		sa = 1;
		for(int j = 2 ;j<=sqrt(a);j++){
			if(a%j == 0){
				sa = sa + j + a/j;
			}
		}
		b = sa; sb = 1;
		for(int j = 2;j<=sqrt(b);j++) {
			if(b%j == 0) {
				sb = sb +j+b/j;
			}
		}
		if(a == sb&&sa == b && a<b) {
			printf("%d %d\n", a, b);
		}
	}
}
