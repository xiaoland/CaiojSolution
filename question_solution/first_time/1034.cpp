#include <cstdio>
#include <cstring>
char a[1100], b[1100], c[1100];
int n, ci;

void dfs(int asp, int al, int bsp, int bl) {
	
	if(asp > al) {
		return ;
	}
	int rp = 0;
	for (int i = bsp; i <= bl; i++) {
		if (b[i] == a[asp]) {
			rp = i - bsp;
			break;
		}
	}
	dfs(asp+1, asp+rp, bsp, bsp+rp-1);
	dfs(asp+rp+1, al, bsp+rp+1, bl);
	c[++ci] = a[asp];
	
}

int main() {
	
	scanf("%s%s", a+1, b+1); // +1?
	n = strlen(a+1);
	dfs(1, n, 1, n);
	printf("%s\n", c+1);
	return 0;
	
}

