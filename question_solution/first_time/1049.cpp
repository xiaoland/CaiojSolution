// author: Lan_zhijiang
// description: 海上救援队
// 这题有个坑，其实通过左右上下能够移动的，就已经是同一舰队了
// 而且它的矩阵输入竟然还是没有空格的字符...
// 4 10
// 0 1 1 1 1 0 0 0 1 1
// 1 0 1 1 1 1 0 1 0 0
// 1 0 1 1 1 0 0 1 1 1
// 0 0 0 0 0 0 0 0 1 1
// 2
// 1 3 2 6
// 1 3 4 10
#include <cstdio>
#include <cstring>
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
struct record {
    int x, y;
    int step;
};
record list[410000], now;
int n, m, head, tail;
int map[1100][1100], sx, sy, ex, ey;
bool v[1100][1100], reach = false;  // 双数检验，其实之前的水桶也可以这么做吧

void bfs() {
    // printf("BFS: start\n");
    head = tail = 1;
    reach = false;
    memset(v, false, sizeof(v));
    while(head<=tail) {
        for(int i = 0; i<=3; i++) {
            now = list[head];
            int xx = now.x + dx[i], yy = now.y + dy[i];
            // printf("BFS: CONTINUE xx: %d, yy: %d, head: %d, tail: %d, value: %d\n", xx, yy, head, tail, map[xx][yy]);
            if (map[xx][yy] == 0) {  // 之前的while是什么鬼...
                // printf("BFS: PASS\n");
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
                        // printf("BFS: END\n");
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

    // printf("cp 1\n");
    scanf("%d%d", &n, &m);
    char st[n+2];
    for(int i = 1; i<=n; i++) {
        scanf("%s", &st[1]);
        for(int j = 1; j<=m; j++) {
            if(st[j] == '1') {
                map[i][j] = 1;
            }
            else {
                map[i][j] = 0;
            }
            // printf("%d", map[i][j]);
        }
        // printf("\n");
    }
    // printf("cp 2\n");
    int t;
    scanf("%d", &t);
    // printf("cp 3\n");
    while(t>=1) {
        t--;
        scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
        // printf("cp 4\n");
        
        list[1].x = sx;
        list[1].y = sy;
        list[1].step = 0;
        // printf("cp 5\n");

        bfs();
        // printf("cp 6\n");
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