#include <cstdio>
using namespace std;

int get_greatest_common_number(int a, int b) {

    int leave_number, last_leave_number;
    leave_number = a%b;
    for(int i = 0; i >= 0; i++) {
        
        if (leave_number == 0) {
            return last_leave_number;
        }
        last_leave_number = leave_number;
        if (i == 0) {
            leave_number = b%leave_number;
        }
        else {
            leave_number = last_leave_number%leave_number;
        }
        // printf("leave_number: %d \n", leave_number);
        // printf("last_leave_number: %d \n", last_leave_number);
    }

}

int main() {

    int a, b, result;
    scanf("%d%d", &a, &b);
    if (b > a) {
        result = get_greatest_common_number(b, a);
    }
    else {
        result = get_greatest_common_number(a, b);
    }
    printf("%d", result);
    return 0;
}
