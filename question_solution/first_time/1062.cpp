// author: Lan_zhijiang
// description: the solution of problem 1062  SKIP SKIP SKIP!!!
// can only finished 80%
 
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
char s[101];
int n, d[101];
char encoder[101][101];
bool f[101];
 
bool compare(int a, int b) {
    int l = strlen(encoder[b]) - 1;
    while (l >= 0) {
        if (s[a] != encoder[b][l]) {
            return false;
        }
        l--;
        a--;
    }
    return true;
}
 
int main() {
    scanf("%s", s+1);
    scanf("%d", &n);
    for (int i = 1; i<=n; i++) {
        scanf("%s", encoder[i]+1);
    }
     
    memset(f, false, sizeof(f));
    memset(d, 0x3f, sizeof(d));
    f[0] = true;
    d[0] = 0;
     
    int l = strlen(s+1);
    // printf("%d\n", l);

    for (int i = 1; i<l; i++) {
        for (int j = 1; j<=n; j++) {
            if (s[i] != encoder[j][strlen(encoder[j]+1)-1]) {
                // printf("check point 1, s[i]: %c, encoder[j]: %d\n", s[i], encoder[j]+1);
            }
            else {
                if (i+1 < strlen(encoder[j]+1)) {
                    // printf("check point 2\n");
                }
                else {
                    if (compare(i, j)) {
                        // printf("check point 3, i: %d, j: %d\n", i, j);
                        int c = i-strlen(encoder[j]+1); // strlen char数组千万不要漏了+1
                        if (c < 0) {
                            c+=1;
                        }
                        if (f[c]) {  // 其实这个没必要的呢
                            // printf("check point 4\n");
                            f[i] = true;
                            d[i] = min(d[i], d[c] + 1);  // 很多时候都是数组问题，多演练一下
                        }
                    }
                }
            }
        }
    }
     
    printf("%d", d[l-1]);
    return 0;
}