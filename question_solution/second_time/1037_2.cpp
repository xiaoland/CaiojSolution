#include <cstdio>
#include <cstring>
int n, m, spx, spy, epx, epy;
int map[110][110];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
struct node {
    int x, y;
}out[1100];
bool ir; // ATTENTION：不要忘了这个

void dfs(int x, int y, int k) {
    out[k].x = x;
    out[k].y = y;
    if(x == epx && y == epy) { // ATTENTION: 必须==
        for(int i = 1; i<k; i++) {  // ATTENTION: i<k
            printf("(%d,%d)->", out[i].x, out[i].y);
        }
        printf("(%d,%d)\n", out[k].x, out[k].y);
        ir = true;
    }
    else {
        for(int i = 0; i<= 3;i++) { // ATTENTION: 循环的是模式序号！
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(map[xx][yy] == 1) {
                map[xx][yy] = 0;
                dfs(xx, yy, k+1);
                map[xx][yy] = 1;
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    memset(map, 0, sizeof(map)); // ATTENTION: 最最关键的地方！一定要写入0，防止跳出范围！
    for(int i = 1; i<=n;i++) {
        for(int j = 1; j<=m;j++) {
            scanf("%d", &map[i][j]);
        }
    }
    scanf("%d%d", &spx, &spy);
    scanf("%d%d", &epx, &epy);
    map[spx][spy] = 0; // ATTENTION: 一定要标记第一个不能走了！因为一开始就会记录进去
    dfs(spx, spy, 1);
    if (ir == false) {
        printf("-1");
    }
}