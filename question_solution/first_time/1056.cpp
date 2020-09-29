// author: Lan_zhijiang
// description: 背包2
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std; // algorithm库一定要有这个 
int n, an[110], tot[11000];
bool f[11000];

int main() {
	int len, x, sum;
	scanf("%d", &n);
	
	for(int i = 1;i <= n; i++) {
//		for(len = 1; len<=110; len++) {  
//			if(scanf("%d", &an[i][len]) == EOF) {
//				i--;
//				break;
//			}
//			if(an[i][len] == -1) {
//				len--;
//				break;
//			}
//		}
		len = 0;
		x = 0;
		while(scanf("%d", &x) != EOF) {
			if(x == -1) {
				break;
			}
			an[++len] = x;
		} 
		
		memset(f, false, sizeof(f));
		f[0] = true;
		sum = 0; // sum是每个序列的最大值，因此要重置
		
		for(int j = 1; j<=len; j++) {
			for(int k = sum; k>=0; k--) {
				if(f[k]) {
					f[k+an[j]] = true;
					sum = max(sum, k+an[j]);
				}
			}
		} 
		for(int j = 0; j<=11000; j++) {
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
	return 0;
}
