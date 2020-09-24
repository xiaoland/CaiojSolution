// a[n]: 这行的和要求  b[m：这列的和要求
// hz[x]: 这行已经累加的和  lz[y]: 这列已经累加的和
// vh[x][i]: 这行是否能填入i这个数  vl[y][i]: 这列是否能填入i这个数 
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int t, n, m, ans;
int a[15], b[15], hz[15], lz[15];
int vh[15][10], vl[15][10];
int c[15][15], cc[15][15];

void dfs(int x, int y) {
    if(x > n && y == 1) {
        bool ir = true;
        for(int i = 1;i<=m;i++) {
            if(lz[i] != b[i]) {
                ir = false;
                break;
            }
        }
        if(ir) {
            ans++;
            for(int i = 1;i<=n;i++) {
                for(int j = 1;j<=m;j++) {
                    cc[i][j] = c[i][j];
                }
            }
        }
        return ;
    }
    if(c[x][y] != 0) {
        if(y<m) {
            dfs(x, y+1);
        }
        else if (y == m && hz[x] == a[x]) {
            dfs(x+1, 1);
        }
    }
    else {
        for(int i = 1;i<=9;i++) {
            if(vh[x][i] && vl[y][i] && hz[x]+i <= a[x] && lz[y]+i <= b[y]) {  // ATTENTION: a, vh, hz->x, b, vl, lz->y
                vh[x][i] = false;
                vl[y][i] = false;
                hz[x]+=i;  // ATTENTION：不要忘了加起来(要对应啊！！！hz->x, lz->y)
                lz[y]+=i;
                c[x][y] = i;
                if(y<m) {
                    dfs(x, y+1);
                }
                else if (y == m && hz[x] == a[x]) {
                    dfs(x+1, 1);
                }
                c[x][y] = 0;
                hz[x]-=i;  // ATTENTION: 也不要忘了减回去(要对应啊！！！hz->x, lz->y)
                lz[y]-=i;
                vh[x][i] = true;
                vl[y][i] = true;
            }
        }
    }
}

int main() {
    scanf("%d", &t);
    while(t--) {  // 变量后缀：调用之后再自减
        scanf("%d%d", &n, &m);
        for(int i = 1;i<=n;i++) {
            scanf("%d", &a[i]);
        }
        for(int i = 1;i<=m;i++) {
            scanf("%d", &b[i]);
        }

        memset(hz, 0, sizeof(hz));
        memset(lz, 0, sizeof(lz));
        memset(vh, true, sizeof(vh));
        memset(vl, true, sizeof(vl));

        for(int i = 1;i<=n;i++) {
            for(int j = 1;j<=m;j++) {
                scanf("%d", &c[i][j]);

                hz[i]+=c[i][j];
                lz[j]+=c[i][j];
                vh[i][c[i][j]] = false;
                vl[j][c[i][j]] = false;
            }
        }
        ans = 0;
        dfs(1, 1);
        if(ans == 1) {
            for(int i = 1;i<=n;i++) {
                for(int j = 1;j<m;j++) {
                    printf("%d ", cc[i][j]);
                }
                printf("%d\n", cc[i][m]);
            }
        }
        else if (ans == 0) {
            printf("No answer.\n");
        }
        else {
            printf("Not unique.\n");
        }
    }
}