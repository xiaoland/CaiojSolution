// author: Lan_zhijiang
// description: 高精度减法 
// 仍需进一步模拟 
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct num {
	int a[1100], len;
	num() {
		len = 0;
		memset(a, 0, sizeof(a));
	}
}; 
num a, b;
char as[1100], bs[1100];

num reduce(num x, num y) {
	num result;
	result.len = x.len;
	
	for(int i = 1; i<=result.len; i++) {
		result.a[i] = x.a[i] - y.a[i];
	}
	
	for(int i = 1; i<=result.len; i++) {  // 减法大于10也就只有负数了 
		if(result.a[i] < 0) {
			result.a[i+1]--;
			result.a[i]+=10;
		}
	}
	
	int i = result.len;
	while(result.a[i+1] > 0) {
		i++;
		result.a[i+1] = result.a[i]/10;
		result.a[i]%10;
	}
	
	while(result.a[i] == 0 && i>1) {
		i--;
	}
	
	result.len = i;
	return result;
}

int compare(num x, num y) {
	
	if(x.len>y.len) {
		return 1;
	}
	else if (x.len<y.len) {
		return -1;
	}
	
	// 同长度比较 
	for(int i = x.len; i>=1; i--) {
		if(x.a[i]>y.a[i]) {
			return 1;
		}
		else if (x.a[i]<y.a[i]) {
			return -1;
		}
	}
	return 0;
	
}

int main() {
	scanf("%s%s", as+1, bs+1);
	a.len = strlen(as+1);
	b.len = strlen(bs+1);
	
	for(int i = 1; i<=a.len; i++) {
		a.a[a.len-i+1] = as[i] - '0';
	}
	for(int i = 1; i<=b.len; i++) {
		b.a[b.len-i+1] = bs[i] - '0';
	}
	
	int t = compare(a, b);
	num c; // C++ ...欸...不能动态创建变量... 
	
	if(t > 0) {
		c = reduce(a, b);
	}
	else if(t < 0) {
		c = reduce(b, a);
		printf("-");
	}
	else {
		printf("0");
		return 0;
	}
	
	for(int i = c.len; i>=1; i--) {
		printf("%d", c.a[i]);
	} 
	printf("\n");
	return 0;
}
