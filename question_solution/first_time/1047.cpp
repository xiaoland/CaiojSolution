#include <cstdio>
#include <cstring>
struct node {
    int a[9];
    int step = 0, record = 0, last = 0;
}; 
node list[410000];
bool find = false;
int head, tail, edk;
bool hash[410000];
int opreation_record[410000];
 
int get_factorial(int x) {
    int result =  1;
    for(int i = 1; i<=x; i++) {
        result = result*i;
    }
    return result;
}
 
int carton(node p) {
    int a[9], len= 0, ans = 0, nac = 0;
    bool appear[9];
    memset(appear, false, sizeof(appear));
     
    for(int i = 1; i<= 8; i++) {
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
    return ans+1;
}

bool compare(node p) {
    for(int i = 1; i<= 8; i++) {
        if(p.a[i] != list[0].a[i]) {
            return false;
        }
    }
    return true;
}

void display(node p) {
    for(int i = 1; i<8; i++) {
        printf("%d ", p.a[i]);
    }
    printf("%d\n", p.a[8]);
}

node opreation(int mode, node p) {
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
    printf("opreation: %d: ", mode); // FOR DEBUG
    display(p);  // FOR DEBUG
    return p;
}
 
int main() {
    for(int i = 1; i<=8; i++) {
        scanf("%d", &list[0].a[i]); // 段错误原因之一：少了&
        list[1].a[i] = i;
    }
    list[1].step = 1;
    edk = carton(list[0]);
    head = tail = 1;
    memset(hash, false, sizeof(hash));
     
    while(head<=tail) {
        for(int i = 1; i<=3; i++) {
            node now = list[head];
            now = opreation(i, now);
            now.step++;
            now.last = head;
            now.record = i;

            int k = carton(now);
            if(hash[k] == false) {
                hash[k] = true;
                // tail++;  // 后缀是调用了再加，前缀是先加了再调用
                list[tail] = now;
                printf("now step: %d\n", now.step);
                if(compare(now)) {
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

    int x = tail, len = 0;
    while(x>1) {
        opreation_record[++len] = list[x].record;
        x = list[x].last;
    }
    char b[5] = "XABC";
    for(int i = len; i>=1; i--) {
        printf("%c", b[opreation_record[i]]);
    }
    return 0;
}