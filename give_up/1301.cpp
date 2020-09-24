#include <cstdio>
#include <cstring>
using namespace std;
struct node {
    int x, y;
    int w1, w2, w; 
}
int expectation, loss, base, biggest, len, k;
int difference, ans; 
node chart[1100];

void auto_genrate(int time) {
    for(int i = 1; i<= time; i++) {
        int a = chart[len].x+1, b, s;
        b = chart[len].y - loss;
        s = a - base;
        len++;
        chart[len].x = a;
        chart[len].y = b;
        chart[len].w = s*b;
    }
}

void read_in() {
    scanf("%d", &expectation);
    for(len = 1; len>=1; len++) {
        scanf("%d%d", &chart[len].x, chart[len].y);
        if(len == 1) {
            base = chart[len].x;
        }
        else if(chart[len].x == -1 && chart[len].y == -1){
            len--;
            break;
        }
        else {
            int s = chart[len].x = base;
            chart[len].w = (s*chart[len].y);
        }
        k = (chart[len-1].y - chart[len].y) / (chart[len].x - chart[len-1].x);
    }
    biggest = chart[len].x;
    scanf("%d", &loss);
}

void w_compute() {
    for(int i = 1; i<= len; i++) {
        int w = chart[i].w, y = chart[i].y, c = 9999;
        for(int j = 1; j<=5; j++)
            if(w + y*j < c) {
                c = w + y*j;
            }
        for(int j = -1; j>=-5; j--) {
            if(w + y*j < c) {
                c = w + y*j;
            }
        }
    }
}

int main() {
    read_in();
    w_compute();

    for(int i = 1; i<= len; i++) {
        if(chart[i])
    }
}