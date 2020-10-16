// author: Lan_zhijiang
// description: the solution of problem 1064
 
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
int n, ans = 0;
int array[1001];
int b[1001];
 
int main() {
    scanf("%d", &n);
    for (int i = 1; i<=n; i++) {
        scanf("%d", &array[i]);
    }
     
    // memset(b, 1, sizeof(b));
    b[1] = 1;
     
    for (int i = 2; i<=n; i++) {
        for (int j = i-1; j>=b[i]; j--) {
            if (array[j] < array[i]) {
                if (b[j] + 1 > b[i]) {
                    b[i] = b[j] + 1;
                }
            }
        }
    }
     
    for (int i = 1; i<=n; i++) {
        if (b[i] > ans) {
            ans = b[i];
        }
    }
     
    printf("%d", ans);
    return 0;
     
}
 