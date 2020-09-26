// author: Lan_zhijiang
// description: 宽搜实现巧取妙量
#include <cstdio>
#include <cstring>
struct bucket {
    int now_volumn, full, loss_s;
    bool is_full = false, is_empty = false;
};
struct record {
    bucket bu[4];
    int step = 0;
};
record list[1000001], now;  // 还要更长，否则不够用 
bool find = false, v[111000];
int head, tail, require;

int hash(record p) {
    return p.bu[1].now_volumn*1000 + p.bu[2].now_volumn*100 + p.bu[3].now_volumn;
}

bool is_repeat(record p) {
    bool result = true;
    for(int i = tail; i>=1; i--) {
        for(int j = 1; j<=3; j++) {
            if(p.bu[j].now_volumn != list[i].bu[j].now_volumn) {
                result = false;
            }
        }
    }
    return result;
}

bool is_end(record p) {
    for(int i = 1; i<=3; i++) {
        // printf("IS END: CHECKING i: %d, now_volumn: %d, is_empty: %d, is_full: %d\n", i, p.bu[i].now_volumn, p.bu[i].is_empty, p.bu[i].is_full);
        if(p.bu[i].now_volumn == require) {
            return true;
        }
    }
    return false;
}

void bfs() {
    head = tail = 1;
    memset(v, false, sizeof(v));
    while(head<=tail) {
            for(int from = 1; from<=3; from++) {
                if(list[head].bu[from].is_empty == false) {
                    
                    for(int to = 1; to<=3; to++) {
                        // printf("BFS: CONTINUE from: %d, to: %d, head: %d, tail: %d\n", from, to, head, tail);
                        if(from != to) {
                            
                            now = list[head];
                            // volumn update
                            int loss_s = now.bu[to].loss_s;  // 要被倒入的桶还有多少才满
                            if(now.bu[from].now_volumn >= loss_s) {  // 是否够倒
                                now.bu[to].now_volumn+=loss_s;
                                now.bu[from].now_volumn-=loss_s;
                            }
                            else {
                                now.bu[to].now_volumn+=now.bu[from].now_volumn;
                                now.bu[from].now_volumn = 0;
                            }

                            // bucket from's status updating
                            if(now.bu[from].now_volumn == 0) {
                                now.bu[from].is_full = false;
                                now.bu[from].is_empty = true;
                            }
                            else if(now.bu[from].now_volumn < now.bu[from].full) {
                                now.bu[from].is_full = false;
                                now.bu[from].is_empty = false;
                            }
                            else {
                                now.bu[from].is_full = true;
                                now.bu[from].is_empty = false;
                            }
                            // bucket to's status updating
                            if(now.bu[to].now_volumn == 0) {
                                now.bu[to].is_full = false;
                                now.bu[to].is_empty = true;
                            }
                            else if(now.bu[to].now_volumn < now.bu[to].full) {
                                now.bu[to].is_full = false;
                                now.bu[to].is_empty = false;
                            }
                            else {
                                now.bu[to].is_full = true;
                                now.bu[to].is_empty = false;
                            }

                            int k = hash(now);
                            if(v[k] == false) {
                                // printf("BFS: SAVING...\n");
                                v[k] = true;
                                now.bu[to].loss_s = now.bu[to].full - now.bu[to].now_volumn;
                                now.bu[from].loss_s = now.bu[from].full - now.bu[from].now_volumn;
                                now.step = list[head].step + 1; // 必须这么做，因为中间有双重for循环，只有在第一个那里才会更新now
                                list[++tail] = now;
                                // printf("BFS: SAVED\n");
                                if(is_end(now)) {
                                    find = true;
                                    return ;
                                }
                            }
                        }
                    }
                }
            }
            head++;
    }
}

int main() {

    bool fail = false;
    while(true) {
        for(int i = 1; i<=3; i++) {
            if(scanf("%d", &list[1].bu[i].full) == EOF) {
                fail = true;
                break;
            }
            
            list[1].bu[i].is_empty = true;
            list[1].bu[i].is_full = false;
            list[1].bu[i].now_volumn = 0;
            list[1].bu[i].loss_s = list[1].bu[i].full - list[1].bu[i].now_volumn;
        }
        list[1].bu[1].is_empty = false;
        list[1].bu[1].is_full = true;
        list[1].bu[1].now_volumn = list[1].bu[1].full;

        if(fail) {
            break;
        }

        scanf("%d", &require);

        list[1].step = 0;
        bfs();
    
        if(find) {
            printf("yes\n");
            printf("%d", list[tail].step);
        }
        else {
            printf("no");
        }
    }
}
