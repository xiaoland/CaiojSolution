// author: Lan_zhijiang
// description: fifth version of proplem 1059
// successful version!
  
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int ml, sn, ans, a, b, c, d;
struct item {
    int type, price, weight, sons[3];
    item() {
        type = -1;
        price = 0;
        weight = 0;
        memset(sons, -1, sizeof(sons));
    }
};
item items[60];
int f[32000];
  
  
void read_in() {
    scanf("%d%d", &ml, &sn);
    for (int i = 1; i<=sn; i++) {
        scanf("%d%d%d", &items[i].price, &items[i].weight, &items[i].type);
        items[i].price/=10;
        items[i].weight*=items[i].price;
        if (items[i].type > 0) {
            items[items[i].type].sons[0] = 0;
            if (items[items[i].type].sons[1] == -1) {
                items[items[i].type].sons[1] = i;
            }
            else {
                items[items[i].type].sons[2] = i;
            }
        }
    }
    ml/=10;
}
  
int main() {
    read_in();
      
    ans = 0;
    memset(f, 0, sizeof(f));
      
    for (int i = 1; i<=sn; i++) {
        if (items[i].type == 0) {
            for(int j = ml; j >= items[i].price; j--) {  // j不总是-1，主要是为了查找上一个
                int a = 0, b= 0, c = 0, d = 0;  // 以后定义了新的变量一定要给个值再使用，不要懒
                a = f[j-items[i].price] + items[i].weight;
                if (items[i].sons[0] == 0) {
                    int lf = items[i].sons[1], ri = items[i].sons[2];
                    if (lf != -1 && items[i].price + items[lf].price <= j) {
                        b = f[j-items[i].price-items[lf].price] + items[i].weight + items[lf].weight;
                    }
                    if (ri != -1 && items[i].price + items[ri].price <= j) {
                        c = f[j-items[i].price-items[ri].price] + items[i].weight + items[ri].weight;
                    }
                    if (ri != -1 && lf != -1 && 
                        items[i].price + items[lf].price + items[ri].price <= j) {
                        d = f[j-items[i].price-items[lf].price-items[ri].price] + items[i].weight + items[lf].weight + items[ri].weight;
                    }
                }
                
                f[j] = max(f[j], max(a, max(b, max(c, d))));  // 最后再统一比较（两个以上）！！！以后这样最保险
                // 如果没一个都max的话，因为数量>2
                // ans = max(ans, f[j]);
            }
        }
    }
      
    printf("%d\n", f[ml]*10);
    return 0;
}