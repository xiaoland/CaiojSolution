#include <cstdio>
#include <cstring>
using namespace std;
// 6
// 1 2 3 4 5 6 7 8
int n, xx = 0, yy = 0;
int map[7][7];
int dx[8] = {-2, -1, -2, 1, 2, 2, 1, -1};
int dy[8] = {-1, 2, 1, 2, 1, -1, -2, -2};
bool ir = false;

void dfs(int x, int y, int k) {

    if (ir) {
        return ;
    }
    if (k > n*n) {
        // print
        ir = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                printf("%d", map[i][j]);
                if (j == n) {
                    printf("\n");
                }
                else {
                    printf(" ");
                }
            }
        }
    }
    else {
        // continue
        for (int i = 0; i <= 7; i++) {
            xx = x + dx[i];  // 放这里，确保xx yy能走，不可以在里面加！！！
            yy = y + dy[i];
            if (xx >= 0 && yy >= 0 && xx <= n && yy <= n) {  // 确保xx yy在1<=x<n之间
                if (map[xx][yy] == 0) {
                    // can be write
                    map[xx][yy] = k;
                    dfs(xx, yy, k+1);
                    if (ir) {
                        return ; // 如果已经有了，那就不用继续了
                    }
                }
            }
        }
    }

}

int main() {

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            map[i][j] = 0;
        }
    }
    // memset(map, 0, sizeof(map));
    // map[0][0] = 1;
    // dfs(0, 0, 2);
    map[1][1] = 1;
    dfs(1, 1, 2);
    if (ir == false) {
        printf("-1");
    }
    return 0;

}