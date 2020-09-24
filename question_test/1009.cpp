#include <cstdio>
using namespace std;
int main() {
	
	int n;
	long long s;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		s = s*i;
	}	
	printf("%lld", s);
}
