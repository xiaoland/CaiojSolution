#include <cstdio>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	int a[110];
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]); // ATTENTION: 千万不可以忘了& 
	}
	int b = a[0];
	for (int i = 1; i < n; i++) {
		if(a[i] > b) {
			b = a[i];
		}
	}
	printf("%d", b);
}
