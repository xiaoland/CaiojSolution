// author: Lan_zhijiang
// description: 高精度乘高精度
#include <cstdio> 
#include <cstring>
#include <algorithm>
struct num {
	int len;
	int a[1100];
	num() {
		len = 0;
		memset(a, 0, sizeof(a));
	}
};
num a, b;
char as[1100], bs[1100];

// num multiply(num x, num y) {
// 	num c;
// 	c.len = x.len+y.len-1;
// 	printf("%d\n", c.len);
	
// 	printf("MULITIPLY: RAW: ");
// 	for(int j = 1; j<=y.len; j++) {
// 	    printf("%d", y.a[j]);
// 	}
// 	printf("\n");

// 	printf("MULITPLY: FIRST STEP: ");
// 	for(int i = 1; i<=x.len; i++) {  // 乘法可是每个数都要乘的哦 
// 		for(int j = 1; j<=y.len; j++) {
// 			c.a[i+j-1]+=x.a[i] * y.a[j];
// 		}
// 		printf("%d ", c.a[i]);
// 	}
// 	printf("\n");
	
// 	printf("MULITPLY: SECOND STEP: ");
// 	for(int i = 1; i<=c.len; i++) {
// 		c.a[i+1] = c.a[i]/10;
// 		c.a[i]%=10;
// 		printf("%d ", c.a[i]);
// 	}
	
// 	int i = c.len;
// 	while(c.a[i+1] > 0) {
// 		i++;
// 		c.a[i+1] = c.a[i]/10;
// 		c.a[i]%=10;
// 		printf("%d", c.a[i]);
// 	}
// 	printf("\n");

// 	while(c.a[i] == 0 && i > 1) {
// 		i--;
// 	}
	
// 	c.len = i;

// 	printf("MULITIPLY: RESULT: ");
// 	for(int j = 1; j<=c.len; j++) {
// 	    printf("%d", c.a[j]);
// 	}
// 	printf("\n");
	
// 	return c;
// }

num multiply(num x, num y) {
	num c;
	c.len = x.len+y.len-1;
	for(int i = 1; i<=x.len; i++) {
		for(int j = 1; j<=y.len; j++) {
			c.a[i+j-1]+=x.a[i]*y.a[j];
		}
	}

	for(int i = 1; i<=c.len; i++) {
		c.a[i+1]+= c.a[i]/10; // 不要把这个弄成=了！是+=！下面那个也是
		c.a[i]%=10;
	}

	int i = c.len;
	while(c.a[i+1] > 0) {
		c.a[i+1]+= c.a[i]/10;
		c.a[i]%=10;
	}

	while((c.a[i] == 0) && (i>1)) {
		i--;
	}

	c.len = i;
	return c;
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
	
	num d = multiply(a, b);
	
	for(int i = d.len; i>=1; i--) {
		printf("%d", d.a[i]);
	}
	printf("\n");
	return 0;
}
