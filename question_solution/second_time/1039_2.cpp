#include <cstdio>
#include <cstring>
int n;
bool ir = false;
int map[8][8];
const int dx[8] = {-2, -1, -2, 1, 2, 2, 1, -1};
const int dy[8] = {-1, 2, 1, 2, 1, -1, -2, -2};
 
void dfs(int x, int y, int k) {
    if(k > n*n) {
        if (ir) {
            return ;
        }
        else {
            for(int i = 1; i<=n;i++) {
                for(int j = 1; j<n;j++) {
                    printf("%d ", map[i][j]);
                }
                printf("%d\n", map[i][n]);
            }
            ir = true;
        }
    }
    else {
        for(int i = 0; i<= 7; i++) {  // 别再把;弄成,了 从0开始啊 
            int xx = x + dx[i];  // 别忘了定义新变量了 
            int yy = y + dy[i];
            if(xx >=1 && xx <= n && yy >=1 && yy <= n) {  // ATTENTION：!!!LEVEL：4!!! 一定要保证xx,yy在数组范围内，否则会index out of range（然而C++不会报错） 
                if(map[xx][yy] == 0) {
                    map[xx][yy] = k;
                    dfs(xx, yy, k+1);
                    map[xx][yy] = 0;
                    if(ir){
                        return ;
                    }
                }
            }
        }
    }
}
 
int main() {
    scanf("%d", &n);
    memset(map, -1, sizeof(map));
    for(int i = 1; i<= n;i++) {
        for(int j = 1; j<= n; j++) {
            map[i][j] = 0;
        }
    }
    map[1][1] = 1;
    dfs(1, 1, 2);
    if(ir == false) {
        printf("-1");
    } 
}