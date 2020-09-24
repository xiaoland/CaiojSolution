#include <cstdio>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	double a[110], s;
	for(int i = 0; i < n; i++) {
		scanf("%lf", &a[i]);
	}
	for(int i = 0; i < n; i++) {
		s = s + a[i];
	}
	printf("%0.2lf", s/n);
}
