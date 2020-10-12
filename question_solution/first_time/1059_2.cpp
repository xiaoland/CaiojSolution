// author: Lan_zhijiang
// description: second version of problem 1059
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int money_limit, item_n, ans;
struct item {
    int type, sons[3], price, weight;
    item() {
        memset(sons, -1, sizeof(sons));
        type = 0;
        price = 0;
        weight = 0;
    }
};
item items[60];
int f[32000];

void read_in() {
    scanf("%d%d", &money_limit, &item_n);
    for (int i = 1; i <= item_n; i++) {
        scanf("%d%d%d", &items[i].price, &items[i].weight, &items[i].type);

        if (items[i].type > 0) {
            items[items[i].type].sons[0] = 0;
            if (items[items[i].type].sons[1] == -1) {
                items[items[i].type].sons[1] = i;
            }
            else if (items[items[i].type].sons[2] == -1) {
                items[items[i].type].sons[2] = i;
            }
        }
        // items[i].price/=10;
    }
}

int main() {
    read_in();
    
    ans = 0;
    memset(f, 0, sizeof(f));

    for (int i = 1; i<=item_n; i++) {
        for (int j = money_limit; j>=items[i].price; j--) {
            f[j] = max(f[j-items[i].price], f[j-items[i].price] + items[i].price*items[i].weight);
            int lf = -1, ri = -1;
            if (items[i].sons[0] == 0) {
                if (items[i].sons[1] != -1) {
                    lf = items[i].sons[1];
                    if (items[i].price + items[lf].price <= j) {
                        f[j] = max(f[j], f[j-items[i].price] + items[lf].price*items[lf].weight + items[i].price*items[i].weight); // ATTENTION HERE
                    }
                }
                if (items[i].sons[2] != -1) {
                    ri = items[i].sons[2];
                    if (items[i].price + items[ri].price <= j) {
                        f[j] = max(f[j], f[j-items[i].price] + items[ri].price*items[ri].weight + items[i].price*items[i].weight);
                    }
                }
                if (ri != -1 && lf != -1) {
                    if (items[i].price + items[ri].price + items[lf].price <= j) {
                        f[j] = max(f[j], f[j-items[i].price] + items[lf].price*items[lf].weight + items[ri].price*items[ri].weight + items[i].price*items[i].weight);
                    }
                }
            }

            ans = max(ans, f[j]);
        }
    }

    printf("%d\n", ans);
    return 0;
}
