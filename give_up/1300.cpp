//  计算器的改良
// p[0]：基本信息 p[1]：左边式子 p[2]：右边式子 
#include <cstdio>
#include <cstring>
using namespace std;
struct node {
    int xs, cs;
};
node p[20];
int main() {
    char a, ch = '1';
    int t = 1;
    p[0].xs = 1;
    while(ch != ' ' && ch != '\n') {
        p[0].cs = 0;
        ch = getchar();
        while(ch >= '0' && ch <= '9') { // 数字读入 
            p[0].cs = p[0].cs*10+ch-48;
            ch = getchar();
        }
        if(ch >= 'a' && ch <= 'z') {  // 字母读入 
            if(p[0].cs == 0) {
                p[0].cs++;
            } 
            p[t].xs+=p[0].xs*p[0].cs;
            a = ch; // 在下次读入前存储上一个 
        }
        else {  // 符号读入 
            p[t].cs+=p[0].xs*p[0].cs;
            if(ch == '=') {
                t++;
                p[0].xs = 1;
            }
            if(ch == '+') { 
                p[0].xs = 1;
            }
            if(ch == '-') {
                p[0].xs = -1;
            }
        }
    }
    p[1].xs-=p[2].xs;
    p[2].cs-=p[1].cs;
    if(p[2].cs == 0) {
        printf("%c=0.000", a);
        return 0;
    }
    printf("%c=%.3lf", a, (1.0*p[2].cs)/(1.0*p[1].xs));
}