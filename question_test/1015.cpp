#include <cstdio>
#include <cmath>
using namespace std;
int pd(int a) {
	int sa = sqrt(a+1);
	for(int i = 2; i <= sa; i++) { // 也可以考虑用i*i<a 
		if(a%i == 0) {
			return 1;
		}
	}
	return 0;
}
int main() {
	int n;
	scanf("%d", &n);
	if (pd(n) == 0) {
		printf("YES");
	}
	else {
		printf("NO");
	}
}
