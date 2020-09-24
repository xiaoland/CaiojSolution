// 两种思路：
// 1、采用全排列，然后对全排列的结果进行验证（可行，但是超过10就会变得很慢）
// 2、先找出哪些数加在一起是素数，然后再对这些组合进行排列输出
#include <cstdio>
#include <cstring>
#include <cmath>
int a[15], v[110];
int n;

bool spd(int c) {
	// int c_s = sqrt(c);
	for(int i = 2;i*i<=c;i++) {
		if(c%i == 0) {
			return false;
		}
	}
	return true;
}

bool pd() {
	int ps = 0;
	for(int i = 1;i<n;i++) {  // 最后一个在一开始已经确认过了，所以就不用循环到n了
		if(i == 1) {
			if(spd(a[i] + a[n])) {
				ps++;
			}
			else {
				return false;
			}
		}
		if(spd(a[i] + a[i+1])) {
				ps++;
		}
		else {
			return false;
		}
	}
	if(ps == n) {
		// printf("TRUE ps: %d\n", ps); // FOR DEBUG
		return true;
	}
	else {
		return false;
	}
}

void dfs(int k) {
	if(k>n) {
		// pd+print
		if(pd()) {
			for(int i = 1;i<=n;i++) {
				printf("%d ", a[i]);
			}
			printf("\n");
		}
	}
	else {
		for(int i = 2;i<=n;i++) {  // ATTENTION: v->i v必须对应i，否则就会重复 a->k
			if(v[i] == 0) {
				v[i] = 1;
				a[k] = i;
				dfs(k+1);
				v[i] = 0;
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	memset(v, 0, sizeof(v));
	// for(int i = 1;i<=n;i++) {
	// 	v[i] = 0;
	// }
	a[1] = 1;
	dfs(2);
} 
