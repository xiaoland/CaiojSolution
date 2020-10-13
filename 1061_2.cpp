// author: Lan_zhijiang
// description: perfect solution of 1061

#include <cstdio>
#include <cstring>

int n;
bool f[1000001];
char s[1000001];
char encoder[6][10] = {"one", "puton", "out", "output", "in", "input"};
int len[6] = {3, 5, 3, 6, 2, 5};

bool compare(int a, int b) {
    int l = len[b] - 1;
    while(l >= 0) {
        if (encoder[b][l] != s[a]) {
            return false;
        }
        l--;
        a--;
    }
}

int main() {
    scanf("%d", &n);

    while (n > 0) {
        n--;
        memset(f, false, sizeof(f));
        f[0] = true;
        
        scanf("%s", s+1);

        int l = strlen(s+1);
        for(int i = 1; i<=l; i++) {
            for(int j = 0; j<=5; j++) {
                if (s[i] != encoder[j][len[j]-1]) {
                    break;
                }
                else {
                    if (i < len[j]) {
                        break;
                    }
                    else {
                        if (compare(i, j)) {
                            if (f[i-len[j]]) {
                                f[i] = true;
                            }
                        }
                    }
                }
            }
        }

        if (f[l]) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
    
}
