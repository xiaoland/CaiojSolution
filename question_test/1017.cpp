// TIME COUNT: 2:24 PASS: 3
#include <cstdio>
#include <sstream>
#include <string>
using namespace std;
int pd(int a) {
    stringstream ss;
    ss<<a;
    string as;
    ss>>as;
    int asl = as.length();
    if(asl < 4) {
        if(as[0] == as[asl-1]) {
            return 0;
        }
    }
    else {
        if(as[0] == as[3] && as[1] == as[2]) {
            return 0;
        }
    }
}
int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    for(int i = x; i <= y; i++) {
        if(pd(i) == 0) {
            printf("%d\n", i);
        }
    }
}