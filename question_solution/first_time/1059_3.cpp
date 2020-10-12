// author: Lan_zhijiang
// description: thrid version of proplem 1059
 
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
                items[items[i].type].sons[1] = items[i].type;
            }
            else {
                items[items[i].type].sons[2] = items[i].type;
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
            for(int j = ml; j >= items[i].price; j--) {
              // ATTENTION: 这里的j不是-1，而是减去item i的价钱，因为这是在上一个结果的基础上添加的啊 
                d = f[j-items[i].price] + items[i].weight;
                if (items[i].sons[0] == 0) {
                    int lf = items[i].sons[1], ri = items[i].sons[2];
                    if (lf != -1 && items[i].price + items[lf].price <= j) {
                        a = f[j-items[i].price-items[lf].price] + items[i].weight + items[lf].weight;
                    }
                    if (ri != -1 && items[i].price + items[ri].price <= j) {
                        b = f[j-items[i].price-items[ri].price] + items[i].weight + items[ri].weight;
                    }
                    if (ri != -1 && lf != -1 && 
                        items[i].price + items[lf].price + items[ri].price <= j) {
                        c = f[j-items[i].price-items[lf].price-items[ri].price] + items[i].weight + items[lf].weight + items[ri].weight;
                    }
                }
                f[j] = max(d, max(a, max(b, c)));
            }
        }
    }
     
    printf("%d\n", f[ml]*10);
    return 0;
}