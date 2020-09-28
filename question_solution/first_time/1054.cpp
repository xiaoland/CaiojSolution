// author: Lan_zhijiang
// description: 高精度乘单精度
// 注意其输入并不是什么字符串，是分开的
#include <cstdio>
#include <cstring>
struct num {
    int a[1100];
    int len;
    num() {
        len = 0;
        memset(a, 0, sizeof(a));
    }
};
num a;
int n;

num multiply_x(num x, int y) {  // 其实也可以用两个结构体来实现，不过读取就会变得很复杂
    num c;
    c.len = x.len;
    for(int i = 1; i<=c.len; i++) {
        c.a[i] = x.a[i]*y;
    }
    for(int i = 1; i<=c.len; i++) {
        c.a[i+1]+=c.a[i]/10;
        c.a[i]%=10;
    }

    int i = c.len;
    while(c.a[i+1] > 0) {
        i++;
        c.a[i+1] = c.a[i]/10;
        c.a[i]%=10;
    }
    while((c.a[i] == 0) && (i>1)) {
        i--;
    }

    c.len = i;
    return c;

}

int main() {
    scanf("%d", &n);
    
    a.len = 1;
    a.a[1] = 1;  // 用1乘于接下来的数
    for(int i = 2; i<=n+1; i++) {  // 从第2位开始写入数组
        scanf("%d", &a.a[i]);
        a = multiply_x(a, a.a[i]);
    }

    for(int i = a.len; i>=1; i--) {
        printf("%d", a.a[i]);
    }
    printf("\n");
    return 0;
}