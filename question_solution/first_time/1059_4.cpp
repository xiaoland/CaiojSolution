// author: Lan_zhijiang
// description: the fourth version of problem 1059

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int ml, n, a, b, c, d;
int v[60][3], p[60][3];
// struct item {
//     int price, weight, sons[3], type;
//     item() {
//         price = 0;
//         weight = 0;
//         memset(sons, -1, sizeof(sons));
//         type = 0;
//     }
// };
// item items[61];
int f[32010];

int main() {
    scanf("%d%d", &ml, &n);
    for (int i = 1; i<=n; i++) {
        scanf("%d%d%d", &a, &b, &c);
        if (c == 0) {
            v[i][0] = a;
            p[i][0] = a*b;
        }
        else {
            if (p[c][1] == 0) {
                v[c][1] = a;
                p[c][1] = a*b;
            }
            else {
                v[c][2] = a;
                p[c][2] = a*b;
            }
        }
        // scanf("%d%d%d", &items[i].price, &items[i].weight, &items[i].type);
        // items[i].price/=10;
        // items[i].weight*=items[i].price;
        // if (items[i].type != 0) {
        //     int father = items[i].type;
        //     items[father].sons[0] = 0;
        //     if (items[father].sons[1] == -1) {
        //         items[father].sons[1] = i;
        //     }
        //     else {
        //         items[father].sons[2] = i;
        //     }
        }
    // ml/=10;

    memset(f, 0, sizeof(f));

    for (int i = 1; i<=n; i++) {
        if (v[i][0] == 0) {
            for(int j = ml; j>=v[i][0]; j--) {
                a = 0; b = 0; c = 0; d = 0;
                if (v[i][0] <= j) {
                    a = f[j-v[i][0]] + p[i][0];
                }
                if (v[i][1] + v[i][0] <= j) {
                    b = f[j-v[i][0]-v[i][1]] + p[i][0] + p[i][1];
                }
                if (v[i][1] + v[i][2] + v[i][0] <= j) {
                    c = f[j-v[i][0]-v[i][1]-v[i][2]] + p[i][0] + p[i][1] + p[i][2];
                }
                if (v[i][2] + v[i][0] <= j) {
                    d = f[j-v[i][0]-v[i][2]] + p[i][0] + p[i][2];
                }
                // a = f[j-items[i].price] + items[i].weight;
                // if (items[i].sons[0] == 0) {
                //     int lf = items[i].sons[1], ri = items[i].sons[2];
                //     if (lf != -1 && items[lf].price + items[i].price <= j) {
                //         b = f[j-items[i].price-items[lf].price] + items[i].weight + items[lf].weight;
                //     }
                //     if (ri != -1 && items[ri].price + items[i].price <= j) {
                //         c = f[j-items[i].price-items[ri].price] + items[i].weight + items[ri].weight;
                //     }
                //     if (ri != -1 && lf != -1 && 
                //         items[i].price + items[lf].price + items[ri].price <= j) {
                //         d = f[j-items[i].price-items[lf].price-items[ri].price] + items[i].weight + items[lf].weight + items[ri].weight;
                //     }
                // }

                f[j] = max(f[j], max(a, max(b, max(c, d))));
            }
        }
    }

    printf("%d\n", f[ml]);
    return 0;
}