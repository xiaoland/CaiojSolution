// 分解数：将自然数n分解为几个整数相加的输出，字典序
#include <cstdio>
#include <cstring>
int n, a[110]; //  v[110];
 
void dfs(int k) {
    if(n == 0) {
        return ;
    }
    if(k > 1) {
        a[k] = n;
        if(a[k-1] <= a[k]) {  // ATTENTION: 后面的数必须大于等于前面的 
            for(int i = 1; i<k;i++) {
                printf("%d+", a[i]);
            }
            printf("%d\n", a[k]);   
        }
    }
    for(int i = a[k-1]; i<= n; i++) {
        a[k] = i;
        n-=i;
        dfs(k+1);
//      a[k] = 0;  // 在这里，没有影响 
        n+=i; // 别把i打成1 
    }
}
 
int main() {
    scanf("%d", &n);
//  memset(v, 0, sizeof(v));  参与加法运算的数可以重复 
//  a[0] = 0;  不可以搭配a[k-1]+1，这样会导致后面的数不能等于前面的数 
    a[0] = 1; // 而是直接从1开始 
    dfs(1);
}