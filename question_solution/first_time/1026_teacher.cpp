#include <cstdio>
using namespace std;
int a[110], len;
int pd(int x) {
    len = 0;
    while(x>0) {  // 利用这种方法可以快速地取到整数的每一位
        len++;
        a[len] = x%10;
        x = x/10;
    }
    for(int i = 1;i<=len/2;i++){
        if(a[i] != a[len-i+1]) { // KNOWLEDGE POINT: len-i+1在最大为j/2的循环中可以做到首尾中间比较
            return 1;
        }
    }
    return 0;
}
int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    for(int i = x; i<=y;i++) {
        if(pd(i) == 0) {
            printf("%d\n", i);
        }
    }
}