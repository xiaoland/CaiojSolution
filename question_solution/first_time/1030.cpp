#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    const int dx[4] = {0, 1, 1, -1};
    const int dy[4] = {1, -1, 0, 1};
    int n, a[110][110];
    scanf("%d", &n);
    memset(a, -1, sizeof(a));
    for(int i = 1; i<=n;i++) {
        for(int j = 1;j<=n;j++) {
            a[i][j] = 0;
        }
    }
    int x = 1, y = 1, k = 1, t = 0;
    while(k<n*n) {
        a[x][y] = k;
        k++;
        if(k>n*n) {
            break;
        }
        while(a[x+dx[t]][y+dy[t]] != 0) {
            t++;
            if( t>3) {
                t = 0;
            }
        }
        x = x + dx[t];
        y = y + dy[t];
        if(t == 0 || t == 2) {
            t++;
        }
    }
    for(int i = 1; i<=n;i++) {
        for(int j = 1;j<=n;j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}