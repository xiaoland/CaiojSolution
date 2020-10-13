// author: Lan_zhijiang
// description: the solution of problem 1060: bag question
 
#include <cstdio>
#include <cstring>
#include <algorithm> 
using namespace std;
 
int n, ans;
int encoder[11];
int f[101];
 
int main() {
    for (int i = 1; i<=10; i++) {
        scanf("%d", &encoder[i]);
    }
    scanf("%d", &n);
     
    memset(f, 999999, sizeof(f));  // 求最小值就一开始直接最大 
    f[0] = 0;
    ans = 0;
     
    for (int i = 1; i<=10; i++) {
        for(int j = 1; j<=n; j++) {  // 虽然还是一维数组，但求最小值从左往右 
            f[j] = min(f[j], f[j-i] + encoder[i]);  // 这么理解：要减去的就是你后面加上的，因为要守恒啊，得失去什么才能得到什么 
        }
    }
     
    printf("%d", f[n]);
    return 0;
}
 