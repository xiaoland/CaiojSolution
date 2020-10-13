// author: Lan_zhijiang
// description: the solution of problem 1061

#include <cstdio>
#include <cstring>
#include <algorithm>

int n;
char encoder[6][10] = {"one", "puton", "out", "output", "in", "input"};  // C艹真麻烦...这样都要二维数组
char s[1000001];
bool f[1000001];

bool compare(int a, int b) {
    
    int wait_compare_length = strlen(encoder[b]);
    for (int i = 1; i <= wait_compare_length; i++) {
        if (s[a-i] != encoder[b][i-1]) {
            return false;
        }
    }
    return true;

}

int main() {
    int t = 0;
    scanf("%d", &t);

    while(t > 0) {
        t--;
        int count = 0;
        memset(f, false, sizeof(f));
        // f[0] = true;

        scanf("%s", s+1);
        int len = strlen(s+1);

        for (int i = 1; i<=n; i++) {
            bool quit = false;

            for (int k = 0; k<=5; k++) {
                if (s[i] != encoder[k][strlen(encoder[k])-1]) {
                    quit = true;
                    break;
                }
                else {
                    if (i < strlen(encoder[k])) {
                        break;
                    }
                    else {
                        if (compare(i, k)) {  // 这里是从i开始倒着比较的，不然f[len]就不可能等于true了(不过本题也可以count=6)
                            if (f[i-strlen(encoder[k])]) {
                                count++;
                                if (count >= 6) {
                                    quit = true;
                                    break;
                                }
                                f[i] = true;  // 诶...反正你得上一个有了，你下面才行
                            }
                        }
                    }
                }
            }
            if (quit) {
                break;
            }
        }

        if (f[len]) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
}
