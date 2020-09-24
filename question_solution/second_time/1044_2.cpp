#include <cstdio>
#include <cstring>
using namespace std;
int t, n, m, ans = 0;
int a[11], b[11], xz[11], yz[11];
int c[11][11], cc[11][11];
bool vx[11][11], vy[11][11];

void dfs(int x, int y) {
    if(x > n && y >= 1) {
        bool pass = true;
        for(int i = 1; i<= m; i++) {
            if(yz[i] != b[i]) {
                pass = false;
                break;
            }
        }
        if(pass) {
            ans++;
            for(int i = 1; i<=n; i++) {
                for(int j =1; j<=m; j++) {
                    cc[i][j] = c[i][j];
                }
            }
        }
        return ;
    }
    if(c[x][y] != 0) {
        if(y < m) {
            y++;
        }
        else if (y == m && xz[x] == a[x]) {
            x++;
            y = 1;
        }
        dfs(x, y);
    }
    else {
        for(int i = 1; i<=9; i++) {
            if(vx[x][i] && vy[y][i] && xz[x]+i<=a[x] && yz[y]+i<=b[y]) {
                c[x][y] = i;
                vx[x][i] = false; vy[y][i] = false;
                xz[x]+=i; yz[y]+=i;
                if(y < m) {
                    y++;
                }
                else if (y == m && xz[x] == a[x]) {
                    x++;
                    y = 1;
                }
                dfs(x, y);
                xz[x]-=i; yz[y]-=i;
                c[x][y] = 0;
                vx[x][i] = true; vy[y][i] = true;
            }
        }
    }
}

int main() {
    scanf("%d", &t);
    while(t>0) {
        t--;
        memset(xz, 0, sizeof(xz));
        memset(yz, 0, sizeof(yz));
        memset(vx, true, sizeof(vx));
        memset(vy, true, sizeof(vy));
        scanf("%d%d", &n, &m);
        for(int i = 1; i<=n; i++) {
            scanf("%d", &a[i]);
        }
        for(int i = 1; i<= m; i++) {
            scanf("%d", &b[i]);
        }
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=m; j++) {
                scanf("%d", &c[i][j]);

                xz[i]+=c[i][j];
                yz[j]+=c[i][j];
                vx[i][c[i][j]] = false;
                vy[i][c[i][j]] = false;
            }
        }
        dfs(1, 1);
        if(ans == 0) {
            printf("No Answer.");
        }
        else if(ans != 1) {
            printf("Not unique.");
        }
        else {
            for(int i = 1; i<= n; i++) {
                for(int j = 1; j<m; j++) {
                    printf("%d ", cc[i][j]);
                }
                printf("%d\n", cc[i][m]);
            }
        }
    }
}