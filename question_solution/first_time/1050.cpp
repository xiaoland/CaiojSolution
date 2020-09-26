// author: Lan_zhijiang
// description: 基因重组
#include <cstdio>
#include <cstring>
struct gene {
    int a[13];
    int step;
};
gene list[410000], now;
bool v[110000], end = false;
int head, tail, len, edk;

int hash(gene now) {
    int ans = 0;
    for(int i = 1; i<=len; i++) {
        ans+=now.a[i]-1;
    }
    return ans;
}

gene opreation(gene p, int mode) {
    gene p2 = p;
    
    if(mode == 1) {
        p.a[1] = p2.a[2];
        p.a[2] = p2.a[1];
    }
    else if(mode == 2) {
        for(int i = 1; i<=len; i++) {
            
        }
    }
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
        char st[2][14];
        scanf("%s", &st[0]);
        scanf("%s", &st[1]);
        for(int j = 0; j<=1; j++) {
            for(int i = 1; i<=len; i++) {
                if(st[j][i] == 'A') {  // C++中的 "" 和 '' 是有区别的
                    list[i].a[i] = 1;
                }
                else if(st[j][i] == 'C') {
                    list[i].a[i] = 2;
                }
                else if(st[j][i] == 'G') {
                    list[i].a[i] = 3;
                }
                else if(st[j][i] == 'T')
                    list[i].a[i] = 4;
                }
            }
        }

        edk = hash(list[0]);
        bfs();
    }
}