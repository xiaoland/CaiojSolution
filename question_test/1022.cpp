// TIME COUNT: 1:04 PASS: 1
#include <cstdio>
using namespace std;
int main() {
	int n, s;
	scanf("%d", &n);
	int x = n;
	while(x>0) {  // KNOWLEDGE POINT: 可以使用这种while取各个位的值 
		s+=x%10;
		x/=10;
	}
	printf("%d", s);
}
