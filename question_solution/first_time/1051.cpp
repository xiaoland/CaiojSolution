// author: Lan_zhijiang
// description: 高精度加法
#include <cstdio>
#include <cstring>
using namespace std;

struct num {
    int len, a[1100];
    num() {  // 结构体初始化
        len = 0;
        memset(a, 0, sizeof(a));
    }
};
num a, b;
char ai[1100], bi[1100];
int an = 0, bn = 0;

void read_in() {
    scanf("%s%s", &ai+1, &bi+1);  // &+数组名+1 表示从数组第一个位开始的地址
    an = strlen(ai+1);
    bn = strlen(bi+1);

    // sort
    for(int i = 1; i<=an; i++) {
        a.a[a.len-i+1] = ai[i] - '0';  // 通过这种奇奇怪怪的方式把char转为int
    }
    for(int i = 1; i<=bn; i++) {
        b.a[b.len-i+1] = bi[i] - '0';
    }
}
