// TIME COUNT: 3:38(3:26) PASS: 1
#include <cstdio>
#include <cstring>
int a[31][31], n, t=0;
int dx[4] = {1, 0 , -1, 0};
int dy[4] = {0, 1, 0, -1};

int dfs(int x, int y, int k) {
    while(k<=n*n) {
        if(a[x+dx[t][y+dy[t]]] != 0) {
            t++;
            if(t>3) {
                t = 0;
            }
        }
        a[x][y] = k;
        x = x + dx[t];
        y = y + dy[t];
        k++;
    }
}

int main(){
    scanf("%d", &n);
    memset(a, -1, sizeof(a));
    for(int i = 1; i<=n;i++) {
        for(int j = 1; j<=n;j++) {
            a[i][j] = 0;
        }
    }
    dfs(1, 1, 1);
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=n;j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}