#include <cstdio>
using namespace std;
int main() {
	int n;
	double s = 1;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		s = s + 1.0/i; // ATTENTION: 写1.0，不可以用1，要实数除实数；还有不要把i弄成n 
	}
	printf("%0.5lf", s);
}
