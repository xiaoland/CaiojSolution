// author: Lan_zhijiang
// description: the solution of problem 1061

#include <cstdio>
#include <cstring>
#include <algorithm>

int t;
char encoder[6][10] = {"one", "puton", "out", "output", "in", "input"};  // C艹真麻烦...这样都要二维数组
char s[1000001];
bool f[1000001], quit;

bool compare(int a, int b) {
    
    int wait_compare_length = strlen(encoder[b]);
    // printf("COMPARE: wcl: %d\n", wait_compare_length);
    for (int j = 0; j < wait_compare_length; j++) {
        // printf("COMPARE: j: %d\n", j);
        if (s[a-j] != encoder[b][wait_compare_length-j-1]) {
            return false;
        }
    }
    return true;

}

int main() {
    scanf("%d", &t);

    while(t > 0) {
        t--;
        memset(f, false, sizeof(f));
        f[0] = true;

        scanf("%s", s+1);
        int len = strlen(s+1);

        for (int i = 1; i<len+1; i++) {

            for (int k = 0; k<=5; k++) {
                quit = true;
                if (s[i] == encoder[k][strlen(encoder[k])-1]) {
                    quit = false;
                    if (i < strlen(encoder[k])) {
                        // printf("MAIN: break because i<encoder[k]\n");
                        break;
                    }
                    else {
                        if (compare(i, k)) {
                            if (f[i-strlen(encoder[k])]) {
                                f[i] = true;  // 诶...反正你得上一个有了，你下面才行
                            }
                        }
                    }
                }
                else {
                    // printf("MAIN: %c and %c\n", s[i], encoder[k][strlen(encoder[k])-1]);
                }
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
