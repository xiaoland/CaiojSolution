// author: Lan_zhijiang
// description: 高精度加法
#include <cstdio>
#include <cstring>
#include <algorithm>
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

num add(num x, num y) {
    
    num result;
    result.len = max(x.len, y.len); // 默认两数中最长的那个为结果长度
    
    // printf("check 1\n");
    for(int i = 1; i<=result.len; i++) {
        result.a[i] = x.a[i] + y.a[i];  // 因为数组全部为0，所以超出了也没关系
    }

    // printf("check 2\n");
    for(int i = 1; i<=result.len; i++) {
        result.a[i+1]+=result.a[i]/10;  // 进位
        result.a[i]%=10;
    }

    // printf("check 3\n");
    int i = result.len;  // 这里是自原有长度后的延伸进位，不能保证两数相加的长度在最长的那个范围内
    while(result.a[i+1] > 0) {  // 只要下一位不是0或负数，我们就继续
        i++;
        result.a[i+1]+=result.a[i]/10;
        result.a[i]%10;
    }

    // printf("check 4\n");
    while(result.a[i] == 0 && i > 1) {  // 将高位处为0的数删掉（减少输出范围），但是要确保至少还有一个0（在0位或其以后）
        i--;
    }

    // printf("check 5\n");
    result.len = i;
    return result;

}

void read_in() {

    scanf("%s%s", ai+1, bi+1);  // 数组名+1 表示从数组第一个位开始的地址  char数组这种读入不用加&
    an = strlen(ai+1);
    bn = strlen(bi+1);
    a.len = an;
    b.len = bn;

    // sort
    for(int i = 1; i<=an; i++) {
        a.a[a.len-i+1] = ai[i] - '0';  // 通过这种奇奇怪怪的方式把char转为int
    }
    for(int i = 1; i<=bn; i++) {
        b.a[b.len-i+1] = bi[i] - '0';
    }

    // start
    num result = add(a, b);

    // printf("check 6, r_len: %d\n", result.len);
    for(int i = result.len; i>=1; i--) {
        // reverse output
        printf("%d", result.a[i]);
    }
    printf("\n");

}

int main() {
    read_in();
    return 0;
}
