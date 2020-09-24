// 8数码问题：宽搜+康托展开
#include <cstdio>
#include <cstring>
using namespace std;

struct cell {
    int map[4][4];
    int step;
    int bx, by;
};
cell start, end, now, last, whole[1100];
bool v[110];
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int get_factorial(int x) {
    int result = 1;
    for(int i = 2; i<=x; i++) {
        result = result*i;
    }
    return result;
}

bool is_end(cell ns, cell ed) {
    
    for(int i = 1; i<=3; i++) {
        for(int j = 1; j<=3; j++) {
            if(ns.map[i][j] != ed.map[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool is_repeat(cell ns) {
    int len = 0, target[10], ans = 0;
    for(int i = 1; i<=3; i++) {
        for(int j = 1; j<=3; j++) {
            len++;
            target[len] = ns.map[i][j]+1;
        }
    }

    int appear[len+1];
    memset(appear, 0, sizeof(appear));
    for(int i = 1; i<= len; i++) {
        int nac = 0;
        appear[target[i]] = 1;
        for(int j = 1; j<target[i]; j++) {
            if(appear[j] == 0) {
                nac++;
            }
        }
        ans = ans + nac*get_factorial(len-i);
    }
    if(v[ans]) {
        return true;
    }
    else {
        v[ans] = true;
        return false;
    }
}

int carton(cell ns) {
    int len = 0, target[10];
    for(int i = 1; i<=3; i++) {
        for(int j = 1; j<=3; j++) {
            target[++len] = ns.map[i][j]+1;
        }
    }

    int appear[len+1], ans = 0;
    memset(appear, 0, sizeof(appear));
    for(int i = 1; i<=9; i++) {
        int nac = 0;
        for(int j = 1; j<target[i]; j++) {
            if(appear[j] == 0) {
                // nac++;
                ans+=get_factorial(9-i);
            }
        }
        appear[target[i]] = 1;
        // ans = ans + nac*get_factorial(9-i);
    }
    return ans+1;
}

int main() {
    for(int i = 1; i<=3; i++) {
        for(int j = 1; j<=3; j++) {
            scanf("%d", &start.map[i][j]);
            if(start.map[i][j] == 0) {
                start.bx = i;
                start.by = j;
            }
        }
    }
    for(int i = 1; i<=3; i++) {
        for(int j = 1; j<=3; j++) {
            scanf("%d", &end.map[i][j]);
            // if(end.map[i][j] == 0) {
            //     end.bx = i;
            //     end.by = j;
            // }
        }
    }
    start.step = 1;
    whole[1] = start;
    int head, tail;
    head = tail = 1;
    int edk = carton(end);
    bool find = false;
    memset(v, false, sizeof(v));
    v[carton(start)] = true;

    while(head<=tail) {
        for(int i = 0; i<= 3; i++) {
            now = whole[head];
            last = whole[head];
            now.bx = last.bx + dx[i];
            now.by = last.by + dy[i];
            if(now.bx >= 1 && now.bx <= 3 && now.by >= 1 && now.by <= 3) {
                
                int nn = now.map[last.bx][last.by];  // 读出上一个状态空格的值
                now.map[last.bx][last.by] = now.map[now.bx][now.by];  // 在上一个空格坐标写入与之交换的值
                now.map[now.bx][now.by] = nn;  // 在与之交换的值的坐标处换成空格的值
                
                now.step = last.step+1;
                // if(is_repeat(now)) {  // 如果重复，则不加入状态队列
                //     continue;
                // }
                int k = carton(now);
                if (v[k] == false) {
                    v[k] = true;
                    tail++;
                    whole[tail] = now;
                    // if(is_end(whole[tail], end)) {  // 判断是否已经为目标状态
                    if(k == edk) {
                        find = true;
                        break;
                    }
                }
            }
        }
        if(find) {
            break;
        }
        head++;
    }
    printf("%d\n", whole[tail].step);
    return 0;
}
