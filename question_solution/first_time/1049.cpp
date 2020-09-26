// author: Lan_zhijiang
// description: 海上救援队
// 这题有个坑，其实通过左右上下能够移动的，就已经是同一舰队了
#include <cstdio>
#include <cstring>
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
struct record {
    int x = 0, y = 0;
    int step = 0;
};
record list[410000], now;
int n, m, head, tail;
int map[1100][1100], sx, sy, ex, ey;
bool v[410000][410000], reach = false;  // 双数检验，其实之前的水桶也可以这么做吧

void bfs() {
    head = tail = 1;
    reach = false;
    memset(v, false, sizeof(v));
    while(head<=tail) {
        for(int i = 0; i<=3; i++) {
            now = list[head];
            int xx = now.x + dx[i], yy = now.y + dy[i];
            while(map[xx][yy] == 0) {
                continue;
            }
            if(xx >= 1 && xx <= n && yy >= 1 && yy <= m) {
                now.step++;
                now.x = xx;
                now.y = yy;
                if(v[xx][yy] == false) {
                    v[xx][yy] = true;
                    list[++tail] = now;
                    if(xx == ex && yy == ey) {
                        reach = true;
                        return ;
                    }
                }
            }
        }
        head++;
    }
}

void read_in() {

    scanf("%d%d", &n, &m);
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=m; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    int t;
    while(t>=1) {
        t--;
        scanf("%d%d%d%d", &sx, &sy, &ex, &ey);

        bfs();
        if(reach) {
            printf("%d\n", list[tail].step);
        }
        else {
            printf("Impossible\n");
        }
    }

}

int main() {
    read_in();
    return 0;
}