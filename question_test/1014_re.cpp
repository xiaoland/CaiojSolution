#include <cstdio>
using namespace std;
int main() {
	
	int n, a[10], s;
	for(int i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &n);
	for(int i = 0; i < 10; i++) {
		if(n + 30 >= a[i]) {
			s+=1;
		}
	}
	printf("%d", s);
	
}
