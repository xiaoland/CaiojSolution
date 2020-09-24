//TIME COUNT: 1:16 PASS: 2
#include <cstdio>
using namespace std;
int main() {
	int x, y;
	scanf("%d%d", &x, &y);
	for(int i = x; i <=y ; i++) {
		int s = 0;
		for(int j = 1; j<i;j++) {
			if(i%j == 0) {
				s = s + j;
			}
		}
		if(s == i) {
			printf("%d\n", i);
		}
	}
}
