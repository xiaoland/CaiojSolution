#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int row[110], col[110], lf[230], ri[230];
int out[110];
int n;

void dfs(int k) {
	
	if(k > n) {
		// print
		for(int i = 1; i <= n; i++) {
			printf("%d", out[i]);
			if (i == n) {
				printf("\n");
			}
			else {
				printf(" ");
			}
		}
	}
	else {
		// continue generate
		for(int j = 1; j <= n; j++) {
			if (row[k] == 0 && col[j] == 0 && lf[j-k+n] == 0 && ri[k+j-1] == 0) {
				row[k] = 1;col[j] = 1;lf[j-k+n] = 1;ri[k+j-1] = 1; // ATTENTION HERE: lf: j-k+n; ri: j+k-1
				out[k] = j;
				dfs(k+1);
				out[k] = 0;
				row[k] = 0;col[j] = 0;lf[j-k+n] = 0;ri[k+j-1] = 0;
			}
		}
	}
	
}


int main() {
	
	scanf("%d", &n);
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	memset(lf, 0, sizeof(lf));
	memset(ri, 0, sizeof(ri));
	dfs(1);
	return 0;
}
