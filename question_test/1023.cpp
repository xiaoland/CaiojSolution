// TIME COUNT: 1:47 PASS: 1 (HAVEN'T PREVIEW)
#include <cstdio>
using namespace std;
int main() {
	int n, s;
	scanf("%d", &n);
	while(n != 1) {
		if(n%2==0) {
			n = n/2;
		}
		else {
			n = 3*n+1;
		}
		s+=1;
	}
	printf("%d", s);
}
