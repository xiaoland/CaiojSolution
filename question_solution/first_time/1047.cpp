#include <cstdio>
#include <cstring>
struct node {
	int a[9], step, record, last;
}; 
node list[410000], now;
bool v[410000], find = false;
int head, tail;

int get_factorial(int x) {
	int result = 1;
	for(int i = 1; i<=x; i++) {
		result*=i;
	}
	return result;
}

int carton(node p) {
	int a[9], len = 0, ans = 0, nac = 0;
	bool appear[9];
	memset(appear, false, sizeof(appear));
	
	for(int i = 1; i<=8; i++) {
		len++;
		a[len] = p.a[i];
	}
	
	for(int i = 1; i<=len; i++) {
		nac = 0;
		for(int j = 1; j<a[i]; j++) {
			if(appear[j] == false) {
				nac++;
			}
		}
		appear[a[i]] = true;
		ans = ans + nac*get_factorial(len-i);
	}
	return ans+1; 
}

node opreation(node p, int mode) {
	node p2 = p;
	if(mode == 1) {
		p.a[1] = p2.a[8];
		p.a[2] = p2.a[7];
		p.a[3] = p2.a[6];
		p.a[4] = p2.a[5];
		p.a[5] = p2.a[4];
		p.a[6] = p2.a[3];
		p.a[7] = p2.a[2];
		p.a[8] = p2.a[1];
	}
	else if(mode == 2) {   // 是插入！不是交换！ 
		p.a[1] = p2.a[4];
        p.a[8] = p2.a[5];
        p.a[2] = p2.a[1];
        p.a[7] = p2.a[8];
        p.a[3] = p2.a[2];
        p.a[4] = p2.a[3];
        p.a[6] = p2.a[7];
        p.a[5] = p2.a[6];
	}
	else if(mode == 3) {
		p.a[3] = p2.a[2];
		p.a[6] = p2.a[3];
		p.a[7] = p2.a[6];
		p.a[2] = p2.a[7];
	}
	return p;
}

int main() {
	for(int i = 1; i<=8; i++) {
		scanf("%d", &list[0].a[i]);
		list[1].a[i] = i;
	}
	
	list[1].step = 0;  // 在这里设为0，题目没有说初始状态也算1步 
	head = tail = 1;
	memset(v, false, sizeof(v));
	int edk = carton(list[0]);
	
	if(carton(list[1]) == edk) {
		find = true;
		printf("%d", list[tail].step);
		return 0;
	}
	while(head<=tail) {
		for(int i = 1; i<=3; i++) {
			now = list[head];
			now = opreation(now, i);
			now.step++;
			now.last = head;
			now.record = i;
			
			int k = carton(now);
			if(v[k] == false) {
				v[k] = true;
				list[++tail] = now;
				if(k == edk) {
					find = true;
					break;
				}
			}
		} 
		if(find) {
			break;
		}
		head++;
	}
	
	printf("%d\n", list[tail].step);
	
	int op_r[410000], len = 0, x = tail;
	while(x>1) {
		len++;
		op_r[len] = list[x].record;
		x = list[x].last;
	}
	char b[5] = "XABC";
	for(int i = len; i>=1; i--) {
		printf("%c", b[op_r[i]]);
	}
	printf("\n");
	return 0;
	
}
