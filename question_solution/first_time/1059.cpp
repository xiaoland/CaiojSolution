// author: Lan_zhijiang
// description: 复杂型背包1
#include <cstdio>
#include <cstring>
#include <algorithm>

int ml, n;
int v[61], w[61], q[61][3];
int a[61][320001];
int out[32001];

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
	
	memset(out, false, sizeof(out));
	out[0] = true;
	
	for(int i = 1; i<=n; i++) {
		for(int j = ml; j>=v[i]; j--) {
			if(q[i][0] == 0) {
				a[i][j] = max(a[i][j-1], a[i][j-1] + v[i]*w[i]);
			}
			else { // 有附件 
				int sl = p[i][1], sr = p[i][2];
				if(sr != -1) {  // 也有右附件 
					if(v[i] + v[sl] + v[sr] <= j) {  // 左右附件都可以加上 
						a[i][j] = max(a[i][j-1], a[i][j-1] + v[i]*w[i]+v[sl]*w[sl]+v[sr]*w[sr]);
					}
					elif (v[i] + v[sr] <= j) { // 只能加上右附件 
						a[i][j] = max(a[i][j-1], a[i][j-1] + v[i]*w[i]+v[sr]*w[sr]);
					}
				}
				else {  // 没有右附件
					if(v[i] + v[sl] <= j) {  // 可以加左附件 
						a[i][j] = max(a[i][j-1], a[i][j-1] + v[i]*w[i]+v[sl]*w[sl]);
					}
				}
			}
		} 
		
		for(int j = 1; j<=ml; j++) {
			// FINISH IN 9.30
		}
	}
	
	int x = 0;
	for(int i = ml; i>=1; i--) {
		x = max(x, out[i]);
	}
}
