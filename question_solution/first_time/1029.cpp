#include <cstdio>
#include <cstring>
using namespace std;
int a[110][110], t = 0, n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


void dfs(int k, int x, int y) {

    while (k<=n*n) {

        
        a[x][y] = k;
        if (a[x + dx[t]][y + dy[t]] != 0) {
            t++;
            if (t > 3) {
                t = 0;
            }
        }
        x = x + dx[t];
        y = y + dy[t];
        k++;
    }

}

int main() {

    scanf("%d", &n);
    memset(a, -1, sizeof(a));
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = 0;
        }
    }
    dfs(1, 1, 1);
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d", a[i][j]);
            if (j == n) {
                printf("\n");
            }
            else {
                printf(" ");
            }
        }
    }
    return 0;


}

// ######## SECOND VERSION ########
// #include <cstdio>
// #include <cstring>
// int a[31][31], n, t = 0;
// int dx[4] = {1, 0, -1, 0};
// int dy[4] = {0, 1, 0, -1};
// void dfs(int x, int y, int k) {

//     while(k<=n*n) {
//         if(a[x+dx[t]][y+dy[t]] != 0) {
//             t++;
//             if(t>3) {
//                 t = 0;
//             }
//         }
//         a[x][y] = k;
//         x = x + dx[t];
//         y = y + dy[t];
//         k++;
//     }

// }
// int main() {
//     scanf("%d", &n);
//     memset(a, -1, sizeof(a));
//     for(int i = 1; i<=n;i++) {
//         for(int j = 1;j<=n;j++) {
//             a[i][j] = 0;
//         }
//     }
//     dfs(1, 1, 1);
//     for(int i = 1;i<=n;i++) {
//         for(int j = 1;j<=n;j++) {
//             printf("%4d", a[i][j]);
//         }
//         printf("\n");
//     }
}