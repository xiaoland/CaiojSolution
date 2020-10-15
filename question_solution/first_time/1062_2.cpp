// author： Lan_zhijiang
// description: the second version solution of problem 1062 SKIP SKIP SKIP!!!
// can only finished 80%
 
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
char input[101];
int f[101];
int n;
char encoder[101][101];
int len[101];
 
bool compare(int a, int b) {
    int l = len[b] - 1;
    while (l > 0) {
        if (input[a-1] != encoder[b][l]) {
            return false;
        }
        l--;
        a--;
    }
    return true;
}
 
int main() {
    scanf("%s", input+1);
    scanf("%d", &n);
    for (int i = 1; i<=n; i++) {
        scanf("%s", encoder[i]+1);
        len[i] = strlen(encoder[i]+1);
    }
     
    int l = strlen(input+1);
    memset(f, 63, sizeof(f));
    f[0] = 0;
     
    for (int i = 0; i <= l; i++) {
        for (int j = 1; j<=n; j++) {
                int c = i - len[j];
                if (f[c] <= 100 && i+1 >= len[j]) {
                    
                    if (compare(i, j)) {
                        f[i] = min(f[i], f[c] + 1);
                    }
                }
        }
    }
     
    printf("%d\n", f[l]);
    return 0;
}