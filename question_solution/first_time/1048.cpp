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
bool find = false;
int head, tail, require;

bool is_repeat(record p) {
    bool result = true;
    for(int i = 1; i<=tail; i++) {
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
        if(p.bu[i].now_volumn == require) {
            return true;
        }
    }
    return false;
}

void bfs() {
    head = tail = 1;
    while(head<=tail) {
        if(find == false) {
            for(int from = 1; from<=3; from++) {
                now = list[head];
                if(now.bu[from].is_empty == false) {

                    for(int to = 1; to<=3; to++) {
                        if(now.bu[to].is_full == false && from != to) {

                            int loss_s = now.bu[to].loss_s;  // 要被倒入的桶还有多少才满
                            if(now.bu[from].now_volumn >= loss_s) {  // 是否够倒
                                now.bu[to].now_volumn+=loss_s;
                                now.bu[from].now_volumn-=loss_s;
                                now.bu[to].is_full = true;
                                now.bu[to].is_empty = false;
                                if(now.bu[from].now_volumn == 0) {
                                    now.bu[from].is_empty = true;
                                    now.bu[from].is_full = false;
                                }
                            }
                            else {
                                now.bu[to].now_volumn+=now.bu[from].now_volumn;
                                now.bu[from].now_volumn = 0;
                                now.bu[from].is_empty = true;
                                now.bu[from].is_full = false;
                            }

                            if(is_repeat(now) == false) {
                                now.bu[to].loss_s = now.bu[to].full - now.bu[to].now_volumn;
                                now.bu[from].loss_s = now.bu[from].full - now.bu[from].now_volumn;
                                now.step = list[head].step + 1; // 必须这么做，因为中间有双重for循环，只有在第一个那里才会更新now
                                list[++tail] = now;
                                if(is_end(now)) {
                                    find = true;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int main() {
    for(int i = 1; i<=3; i++) {
        scanf("%d", &list[1].bu[i].full);
        if(i == 1) {
            list[1].bu[i].is_empty = false;
            list[1].bu[i].is_full = true;
            list[1].bu[i].now_volumn = list[1].bu[i].full;
        }
        else {
            list[1].bu[i].is_empty = true;
            list[1].bu[i].is_full = false;
            list[1].bu[i].now_volumn = 0;
        }
        list[1].bu[i].loss_s = list[1].bu[i].full - list[1].bu[i].now_volumn;
    }
    scanf("%d", &require);

    list[1].step = 0;
    bfs();
    
    if(find) {
        printf("yes");
        printf("%d", list[tail].step);
    }
    else {
        printf("no");
    }
}
