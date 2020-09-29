// author: Lan_zhijiang
// description: 背包2：REWRITE
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool f[11000];
int tot[11000], a[110], n;

int main() {
	int sum, len, x;
	scanf("%d", &n);
	
	for(int i = 1; i<=n; i++) {
		len = 0;
		x = 0;
		while(scanf("%d", &x) != EOF) {
			if(x == -1) {
				break;
			}
			a[++len] = x;
		}
		
		sum = 0;
		memset(f, false, sizeof(f));
		f[0] = true;
		
		for(int j = 1; j<=len; j++) {
			for(int k = sum; k>=0; k--) {
				if(f[k]) {
					f[k+a[j]] = true;
					sum = max(sum, k+a[j]);
				}
			}
		}
		
		for(int j = 0; j<=11000; j++) { // 从0开始 
			if(f[j]) {
				tot[j]++;
			}
		}
	}
	
	for(int i = 11000; i>=0; i--) {
		if(tot[i] == n) {
			printf("%d\n", i);
			break;
		}
	}
} 
