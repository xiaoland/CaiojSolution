// author: Lan_zhijiang
// description: 复杂型背包
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int ml, n;
int v[61], w[61], q[61][3];
int a[320001];
// int out[32001];

void read_in() {
	int type;
	memset(q, -1, sizeof(q));
	scanf("%d%d", &ml, &n);
	for(int i = 1; i<=n; i++) {
		scanf("%d%d%d", &v[i], &w[i], &type);
		v[i]/=10;
		if(type != 0) {
			if(q[type][1] != -1) {
				q[type][2] = i;
			}
			else {
				q[type][1] = i;
			}
		}
		else {
			q[i][0] = 0;
		}
	}
	ml/=10;
} 

int main() {
	read_in();
	
	memset(a, 0, sizeof(a));
	a[0] = 0;
	int x = 0;
	
	for(int i = 1; i<=n; i++) {
		for(int j = ml; j>=v[i]; j--) {
			printf("i: %d, j: %d\n", i, j);
			if(q[i][0] == 0) {  // 主件
				printf("    MAIN\n");
				a[j] = max(a[j-1], a[j-1] + v[i]*w[i]);
			}
			else { // 附件
				printf("    SON\n");
				int sl = q[i][1], sr = q[i][2];
				if(sr != -1) {  // 若有右孩子 
					if(v[i] + v[sl] + v[sr] <= j) {  // 若两个孩子都可以 
						printf("      ADD BOTH\n");
						a[j] = max(a[j-1], a[j-1] + v[i]*w[i]+v[sl]*w[sl]+v[sr]*w[sr]);
					}
					else if (v[i] + v[sl] <= j) {  // 只有左孩子就可以
						printf("      ADD LEFT\n");
						a[j] = max(a[j-1], a[j-1] + v[i]*w[i]+v[sl]*w[sl]);
					}
					else if (v[i] + v[sr] <= j) { // ֻ只有右孩子就可以
						printf("      ADD RIGHT\n");
						a[j] = max(a[j-1], a[j-1] + v[i]*w[i]+v[sr]*w[sr]);
					}
				}
				else {  // 没有右孩子
					if(v[i] + v[sl] <= j) {  //  左孩子可以
						printf("      ADD LEFT\n"); 
						a[j] = max(a[j-1], a[j-1] + v[i]*w[i]+v[sl]*w[sl]);
					}
				}
			}
			x = max(x, a[j]);
		} 
	}
	
	printf("%d\n", x);
	return 0;
}
