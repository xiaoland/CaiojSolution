#include <cstdio>
#include <cstring>
using namespace std;
struct node {
    int x, y;
    int a[4][4];
    int step;
};
node list[410000], now;
int head, tail, d[11];
bool v[410000];  // list和v都至少得长度410000，否则会溢出或重叠
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
    int a[10], len= 0, ans = 0, nac;
    bool appear[10];
    memset(appear, false, sizeof(appear));
    
    for(int i = 1; i<=3; i++) {
        for(int j = 1;j <=3; j++) { // j不能=，别忘了
            len++;
            a[len] = p.a[i][j]+1;
        }
    }

    for(int i = 1; i<=len; i++) {
        nac = 0; // 别忘了这个，如果k过大，都是缺这个的错
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
    d[0] = 1;
    for(int i = 1; i<=9; i++) {
        d[i] = d[i-1]*i;
    }

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
    
    list[1].step = 1;
    head = tail = 1;
    bool find = false;
    memset(v, false, sizeof(v));
    int edk = carton(list[0]);
    
    while(head<=tail) {
        for(int i = 0; i<=3; i++) {
            now = list[head];
            int xx = now.x + dx[i], yy = now.y + dy[i];
            if(xx <= 3 && xx >= 1 && yy <= 3 && xx >= 1) {
                int t = now.a[xx][yy]; // t是读出要被空格代替的数
                now.a[xx][yy] = now.a[now.x][now.y];  // 将新的空格写入
                now.a[now.x][now.y] = t;  // 完成与原来空格的替换
                now.x = xx;
                now.y = yy;
                now.step+=1;

                int k = carton(now);
                if(v[k] == false) {
                    tail++;
                    v[k] = true;
                    list[tail] = now;
                    if(k == edk) {
                        printf("%d\n", now.step);
                        find = true;
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
