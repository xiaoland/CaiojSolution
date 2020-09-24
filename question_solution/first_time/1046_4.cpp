#include <cstdio>
#include <cstring>
using namespace std;
struct node {
    int x, y;
    int a[4][4];
    int step;
};
node list[410000], now;
bool v[410000], find;
int head, tail, edk, d[10];
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};

int get_factorial(int x) {
    int result = 1;
    for(int i = 1; i<=x; i++) {
        result*=i;
    }
    return result;
}

int carton(node p) {
    int len = 0, ans = 0, nac = 0;
    int a[10];
    bool appear[15];
    memset(appear, false, sizeof(appear));

    for(int i = 1; i<=3; i++) {
        for(int j = 1; j<=3; j++) {
            len++;
            a[len] = p.a[i][j]+1;
        }
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

int main() {
    for(int i = 1; i<=3; i++) {
        for(int j = 1; j<=3; j++) {
            scanf("%d", &list[1].a[i][j]);
            if(list[1].a[i][j] == 0) {
                list[1].x = i;
                list[1].y = j;
            }
        }
    }

    for(int i = 1; i<=3; i++) {
        for(int j = 1; j<=3; j++) {
            scanf("%d", &list[0].a[i][j]);
        }
    }

    edk = carton(list[0]);
    memset(v, false, sizeof(v));
    list[1].step = 1;
    head = tail = 1;
    find = false;

    while(head<=tail) {
        for(int i = 0; i<=3; i++) {
            now = list[head];
            int xx = now.x + dx[i], yy = now.y + dy[i];
            if(xx >=1 && xx <= 3 && yy >= 1 && yy <= 3) {
                int t = now.a[xx][yy];
                now.a[xx][yy] = now.a[now.x][now.y];
                now.a[now.x][now.y] = t;
                now.x = xx;
                now.y = yy;
                now.step+=1;
				
                int k = carton(now);
                if(v[k] == false) {
                    v[k] = true;
                    tail++;
                    list[tail] = now;
                    if(k == edk) {
                        find = true;
                        printf("%d\n", list[tail].step);
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
    return 0;
}