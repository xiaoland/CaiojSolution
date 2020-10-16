// author: Lan_zhijiang
// description: the solution of problem 1063
 
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
int days;
double d[110], m[110], r[110];
 
int main() {
     
    memset(d, 0.0, sizeof(d));
    memset(m, 0.0, sizeof(m));
     
    scanf("%d", &days);
    scanf("%lf", &r[1]);
     
    m[1] = r[1];
    d[1] = 100.0;
    r[1] = 100.0/r[1];
     
    for (int i = 2; i<=days; i++) {
        scanf("%lf", &r[i]);
        r[i] = 100.0/r[i];
         
        d[i] = max(d[i-1], m[i-1]*r[i]); // r->i 看昨天继承什么值才能在【今天】 
        m[i] = max(m[i-1], d[i-1]/r[i]); // 拿到最大值 
    }
     
    printf("%.2lf", d[days]);
    return 0;
      
}