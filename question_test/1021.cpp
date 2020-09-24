// TIME COUNT: 2:27 PASS: 2
#include <cstdio>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i<=n/2+1;i++){
		for(int j = 1; j<=n/2+1-i;j++) {
			printf(" ");
		}
		for(int j = 1;j<=i*2-1;j++){ 
			printf("*");
		}
		printf("\n");
	}
	for(int i = n/2;i>=1;i--) {
		for(int j = 1; j<=n/2+1-i;j++){
			printf(" ");
		}
		for(int j = 1;j<=i*2-1;j++){
			printf("*");
		}
		printf("\n");
	}
}
