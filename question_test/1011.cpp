#include <cstdio>
#include <cstring>
using namespace std;
int main() {
	
	int n;
	double a[110], s = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &a[i]);  // ATTENTION��С�Ĵ��%d,Ӧ����%lf 
	}
	for(int i = 0; i < n; i++) {
		s = s + a[i];
	}
	printf("%0.2lf", s/n);
	
}
