#include <cstdio>
#include <cstring>
using namespace std;
int n, m, t;
int spx, spy, epx, epy;
bool ir = false;
struct node {
    int x, y;
}out[4400];
int map[20][20];
// const int dx[4] = {0, -1, 0, 1};
// const int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, -1, 0, 1};  // ATTENTION: has to use this order!
int dy[4] = {-1, 0, 1, 0};

void dfs(int x, int y, int k) {

    out[k].x = x;
    out[k].y = y;
    if (x == epx && y == epy) {
        // print
        // for(int i = 1; i <= k; i++) {
        for(int i = 1; i < k; i++) {
            printf("(%d,%d)->", out[i].x, out[i].y);
        }
        printf("(%d,%d)\n", out[k].x, out[k].y);
        ir = true;
            // printf("(%d,%d)", out[i].x, out[i].y);
            // if (i == k) {
            //     printf("\n");
            // }
            // else{
            //     printf("->");
            // }
        // }
    }
    else {
        // continue finding the road
        for (int i = 0; i <= 3; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (map[xx][yy] == 1) {
                // map[x+dx[i]][y+dy[i]] = 0;  // promise there is no repeat point in !one! way
                // dfs(x+dx[i], y+dy[i], k+1);
                // map[x+dx[i]][y+dy[i]] = 1;
                map[xx][yy] = 0;
                dfs(xx, yy, k+1);
                map[xx][yy] = 1;
            }
        }
    }

}

int main() {

    scanf("%d%d", &n, &m);
    memset(map, 0, sizeof(map)); // before write into the list, you have to give it a num
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    scanf("%d%d", &spx, &spy);
    scanf("%d%d", &epx, &epy);
    // out[1].x = spx;
    // out[1].y = spy;
    map[spx][spy] = 0;
    dfs(spx, spy, 1);
    if (ir == false) {
        printf("-1\n");
    }
    return 0;

}
