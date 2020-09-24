#include <cstdio>
#include <cstring>
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
struct node {
    int x, y, a[4][4], dep;
}list[11100], st, ed;
int head, tail;
bool compare(node p1, node p2) {
    for(int i = 1; i<=3; i++) {
        for(int j = 1; j<= 3; j++) {
            if (p1.a[i][j]!=p2.a[i][j]) {
                return false;
            }
        }
    }
    return true;
}
 
bool is_repeat(node now) {
    for(int i = 1; i<= tail; i++) {
        if(compare(now, list[i])) {
            return true;
        }
    }
    return false;
}
 
int main() {
    for(int i = 1; i<= 3; i++) {
        for(int j = 1; j<=3; j++) {
            scanf("%d", &st.a[i][j]);
            if (st.a[i][j] == 0) {
                st.x = i;
                st.y = j;
            }
        }
    }
    st.dep = 1;
     
    for(int i = 1;i<=3;i++) {
        for(int j = 1; j<=3; j++) {
            scanf("%d", &ed.a[i][j]);
        }
    }
     
    list[1] = st;
    head = tail = 1;
    bool find = false;
    while (head<=tail) {
        int x = list[head].x, y = list[head].y;
        for(int i = 0; i<= 3; i++) {
            int tx = x + dx[i], ty = y + dy[i];
            if(tx >= 1 && tx <= 3 && ty >= 1 && ty <= 3) {
                node now = list[head];
                now.dep = list[head].dep+1;
                now.x = tx;
                now.y = ty;
                 
                int t = now.a[x][y];
                now.a[x][y] = now.a[tx][ty];
                now.a[tx][ty] = t;
                 
                if(is_repeat(now)) {
                    continue;
                }
                tail++;
                list[tail] = now;
                if(compare(list[tail], ed)) {
                    printf("%d\n", list[tail].dep);
                    return 0;
                }
            }
        }
        head++;
    }
}