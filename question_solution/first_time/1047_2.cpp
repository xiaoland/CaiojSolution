#include <cstdio>
#include <cstring>
struct node {
    int a[9], step, record, last;
};
node list[410000], now;
int head, tail;
bool v[410000], find;

int get_factorial(int x) {
    int result = 1;
    for(int i = 1; i<=x; i++) {
        result*=i;
    }
    return result;
}

int carton(node p) {
    int a[9], len = 0, nac = 0, ans = 0;
    bool appear[9];
    memset(appear, false, sizeof(appear));

    for(int i = 1; i<=8; i++) {
        len++;
        a[len] = p.a[i];
    }

    for(int i = 1; i<=len; i++) {
        nac = 0;
        for(int j = 1; j<a[i]; j++) {
            if(appear[j] == false) {
                nac++;
            }
        }
        appear[a[i]] = true;
        ans = ans + nac*get_factorial(len-i);
    }
}

node opreation(node p, int mode) {
    node p2 = p;
    if(mode == 1) {
        p.a[1] = p2.a[8];
        p.a[2] = p2.a[7];
        p.a[3] = p2.a[6];
        p.a[4] = p2.a[5];
        p.a[8] = p2.a[1];
        p.a[7] = p2.a[2];
        p.a[6] = p2.a[3];
        p.a[5] = p2.a[4];
    }
    else if(mode == 2) {
        p.a[1] = p2.a[4];
        p.a[8] = p2.a[5];
        p.a[4] = p2.a[1];
        p.a[5] = p2.a[8];
    }
    else if(mode == 3) {
        p.a[3] = p2.a[2];
        p.a[6] = p2.a[3];
        p.a[7] = p2.a[6];
        p.a[2] = p2.a[7];
    }
    return p;
}

int main() {
    for(int i = 1; i<=8; i++) {
        scanf("%d", &list[0].a[i]);
        list[1].a[i] = i;
    }

    list[1].step = 1;
    head = tail = 1;
    int edk = carton(list[0]);
    find = false;
    memset(v, false, sizeof(v));
    
    while(head<=tail) {
        for(int i = 1; i<=3; i++) {
            now = list[head];
            now = opreation(now, i);
            now.step++;
            now.last = head;
            now.record = i;

            int k = carton(now);
            if(v[k] == false) {
                v[k] = true;
                list[++tail] = now;
                if(k == edk) {
                    find = true;
                    break;
                }
            }
        }
        if(find) {
            break;
        }
        head++;
    }

    printf("%d\n", list[tail].step);

    int opreation_record[410000], x = tail, len = 0;
    while(x>1) {
        opreation_record[++len] = list[x].record;
        x = list[x].last;
    }
    char b[5] = "XABC";
    for(int i = len; i>=1; i++) {
        printf("%c", b[opreation_record[i]]);
    }

}