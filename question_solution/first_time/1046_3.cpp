// 8数码问题：宽搜+康托展开
#include <cstdio>
#include <cstring>
struct cell {
    int x, y;
    int map[4][4];
    int step;
}; 
cell list[1100];
int hash_list[410000];
int d[10];
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
 
int get_chengjie(int x) {
    int s = 1;
    for(int i = 1; i<=x; i++) {
        s = s*i;
    }
    return s;
}
 
int carton(cell p) {
    int a[10], appear[10], ans = 0, nac = 0, len = 1;
    memset(appear, 0, sizeof(appear));
     
    for(int i = 1; i<= 3; i++) {
        for(int j = 1; j<= 3; j++) {
            a[len] = p.map[i][j]+1; // 不能有0，最少为1 
            len++;
        }
    }
     
    for(int i = 1; i<=9; i++) {
        appear[a[i]] = 1;
        nac = 0;
        for(int j = 1; j<a[i]; j++) {
            if(appear[j] == 0) {
                nac++;
                // ans+= d[9-i];
            }
        }
        ans = ans + nac*d[9-i];
    }
    return ans+1;
}
 
int main() {
     
    d[0] = 1;
    for(int i = 1; i<= 8; i++) {
        d[i] = i*d[i-1];
    }
     
    for(int i = 1; i<= 3; i++) {
        for(int j = 1; j<= 3; j++) {
            scanf("%d", &list[1].map[i][j]);
            if(list[1].map[i][j] == 0) {
                list[1].x = i;
                list[1].y = j;
            }
        }
    }
    for(int i = 1; i<=3; i++) {
        for(int j = 1; j<=3; j++) {
            scanf("%d", &list[0].map[i][j]);
            if(list[0].map[i][j] == 0) {
                list[0].x = i;
                list[0].y = j;
            }
        }
    }
     
    list[1].step = 1;
     
    int edk = carton(list[0]);
    // hash_list[carton(list[1])] = 1;
    hash_list[edk] = 1;
    int head, tail;
    bool find = false;
    head = tail = 1;
    cell now;
    while(head<=tail) {
         
        for(int i = 0; i<=3; i++) {
            now = list[head];
            now.x = list[head].x + dx[i];
            now.y = list[head].y + dy[i];
             
            if(now.x <= 3 && now.y <= 3 && now.y >= 1 && now.x >= 1) {
                int t = now.map[list[head].x][list[head].y];
                now.map[list[head].x][list[head].y] = now.map[now.x][now.y];
                now.map[now.x][now.y] = t;
                 
                int k = carton(now);
                if(k == edk) {
                    now.step++;
                    tail++;
                    list[tail]= now;
                    find = true;
                    break;
                }
                else {
                    if(hash_list[k] != 0) {
                        continue;
                    }
                    else {
                        now.step++;
                        tail++;
                        list[tail] = now;
                        break;
                    }
                }
            }
        }
        if(find) {
            break;
        }
        head++;
         
    }
    printf("%d", list[tail].step);
    return 0;
}