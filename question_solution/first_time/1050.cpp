// author: Lan_zhijiang
// description: 基因重组
#include <cstdio>
#include <cstring>
using namespace std;
struct gene {
    int a[13];
    int step;
};
gene list[2100000], now;  // 变态长模式（计算空间复杂度）
bool v[21000000], end = false;
int head, tail, len, edk;

int hash(gene now) {
    int ans = 0;
    for(int i = 1; i<=len; i++) {
        ans*=4;
        ans+=now.a[i]-1;
        // printf("HASH: i: %d, a: %d, ans: %d\n", i, now.a[i], ans);
    }
    return ans;
}

gene opreation(gene p, int mode) {
    gene p2 = p;
    // printf("OPREATION: mode: %d\n", mode);
    if(mode == 1) {
        p.a[1] = p2.a[2];
        p.a[2] = p2.a[1];
    }
    else if(mode == 2) {  // ERROR!  1422->4221
        for(int i = 1; i<=len; i++) {
            int j = i + 1;
            if(j > len) {  // 是 > 大于啊，不是小于
                j = 1;
            }
            p.a[i] = p2.a[j];
        }
    }
    return p;
}

void bfs() {
    head = tail = 1;
    memset(v, false, sizeof(v));
    end = false;
    while(head<=tail) {
        for(int i = 1; i<=2; i++) {
            now = list[head];
            now = opreation(now, i);
            now.step++;

            int k = hash(now);
            if(v[k] == false) {
                v[k] = true;
                list[++tail] = now;
                if(k == edk) {
                    end = true;
                    break;
                }
            }
        }
        if(end) {
            break;
        }
        head++;
    }
}

void read_in() {
    while(true) {
        scanf("%d", &len);
        if(len == 0) {
            break;
        }
        char st[14];
        for(int j = 1; j>=0; j--) {
            scanf("%s", &st[1]);
            for(int i = 1; i<=len; i++) {
                if(st[i] == 'A') {  // C++中的 "" 和 '' 是有区别的
                    list[j].a[i] = 1;
                }
                else if(st[i] == 'C') {
                    list[j].a[i] = 2;
                }
                else if(st[i] == 'G') {
                    list[j].a[i] = 3;
                }
                else if(st[i] == 'T') {
                    list[j].a[i] = 4;
                }
            }
        }
        list[1].step = 0;
        edk = hash(list[0]);
        if(hash(list[1]) == edk) {  // 又忘了这种可能性么...
            end = true;
        }
        else {
            bfs();
        }

        if(end) {
            printf("%d\n", list[tail].step);
        }
    }
}

int main() {
    read_in();
    return 0;
}