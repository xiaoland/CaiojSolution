#include <cstdio>
using namespace std;
int main() {
	int n;
	double s = 1;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		s = s + 1.0/i; // ATTENTION: д1.0����������1��Ҫʵ����ʵ�������в�Ҫ��iŪ��n 
	}
	printf("%0.5lf", s);
}
