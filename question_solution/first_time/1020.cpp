#include <cstdio>
#include <cmath>

void get_perfect_number(int start, int end) {
	
	int all_arr[end-start+1], approximate_arr[end-start+1][1100];
	
	for(int i = 1; i <= end-start; i++) {
		
		int now_number = start + i;
		all_arr[i] = now_number;
		approximate_arr[i][0] = 1;
		
		int approximate_saving_index = 1;
		
		int n_s = sqrt(now_number);
		for(int a = 2; a <= n_s; a ++) {
			
			if (now_number%a == 0) {
				approximate_arr[i][approximate_saving_index] = a;
				approximate_saving_index++;
				approximate_arr[i][approximate_saving_index] = now_number/a;
				approximate_saving_index++;
			}
			
		}
		
	}
	
	for(int i = 0; i <= end-start; i++) {
		
		int add = 0, w_a, now_number;
		now_number = all_arr[i];
		for(int a = 0; a >= 0; a++) {
			
			w_a = approximate_arr[i][a];
			if (w_a == 0) {
				break;
			}
			else {
				add = add + w_a;
			}
			
		}
		
		if (add == now_number) {
			if (now_number == 0 || now_number == 1) {
				continue;
			}
			else {
				printf("%d\n", now_number);
			}
			
		}
		
	}
	
	
		
}

int main() {
	
	int x, y;
	scanf("%d%d", &x, &y);
	if (x > y) {
		get_perfect_number(y, x);
	}
	else {
		get_perfect_number(x, y);
	}
	return 0;
	
}

