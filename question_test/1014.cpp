#include <cstdio>
using namespace std;
int main() {
	int n, a[110], s = 0; // ATTENTION: 要加的数必须先初始化 
	for(int i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &n);
	for(int i = 0; i < 10; i++) {
		if(a[i] <= n+30) {
			s+=1;
		}
	}
	printf("%d", s);
}
