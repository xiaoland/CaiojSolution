#include <cstdio>
#include <cstring>
using namespace std;
int t, n, m, ans = 0;
int a[11], b[11], xz[11], yz[11];
bool vx[11][11], vy[11][11];
int c[11][11], cc[11][11];

void dfs(int x, int y) {
    if(x > n && y == 1) {
        bool pass = true;
        for(int i = 1; i <= m; i++) {
            if(yz[i] != b[i]) {
                pass = false;
                break;
            }
        } 
        if(pass) {
            ans++;
            for(int i = 1; i<= n; i++) {
                for(int j = 1; j<= m; j++) {
                    cc[i][j] = c[i][j];
                }
            }
        }
        return ;
    }
    if(c[x][y] != 0) {
        if(y < m) {
            dfs(x, y+1);
        }
        else if(y == m && xz[x] == a[x]) {
            dfs(x+1, 1);
        }
    }
    else {
        for(int i = 1; i<= 9; i++) {
            if(vx[x][i] && vy[y][i] && xz[x] + i <= a[x] && yz[y] + i <= b[y]) {
                vx[x][i] = false; vy[y][i] = false;
                xz[x]+=i; yz[y]+=i;
                c[x][y] = i;
                if(y < m) {
                    dfs(x, y+1);
                }
                else if(y == m && xz[x] == a[x]) {
                    dfs(x+1, 1);
                }
                c[x][y] = 0;
                xz[x]-=i; yz[y]-=i;
                vx[x][i] = true; vy[y][i] = true;
            }
        }
    }
}

int main() {
    scanf("%d", &t);
    while(t>0) {
        t--;
        memset(vx, true, sizeof(vx));
        memset(vy, true, sizeof(vy));
        memset(xz, 0, sizeof(xz));
        memset(yz, 0, sizeof(yz));
        scanf("%d%d", &n, &m);
        for(int i = 1; i<=n; i++) {
            scanf("%d", &a[i]);
        }
        for(int i = 1; i<=m; i++) {
            scanf("%d", &b[i]);
        }
        for(int i = 1; i<= n; i++) {
            for(int j = 1; j<=m; j++) {
                scanf("%d", &c[i][j]);

                xz[i]+=c[i][j];
                yz[j]+=c[i][j];
                vx[i][c[i][j]] = false;
                vy[j][c[i][j]] = false;
            }
        }
        ans = 0; // 不要忘了重置ans
        dfs(1, 1);
        if(ans == 1) {
            for(int i = 1; i<=n; i++) {
                for(int j = 1; j<m; j++) {
                    printf("%d ", cc[i][j]);
                }
                printf("%d\n", cc[i][m]);
            }
        }
        else if(ans == 0) {
            printf("No answer.\n");  // 别漏了\n
        }
        else {
            printf("Not unique.\n");
        }
    }
}