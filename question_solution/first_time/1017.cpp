#include <cstdio>
#include <sstream>
#include <string>
using namespace std;

int pd(int a) {
	
	stringstream ss;
	ss<<a;
	string a_str;
	ss>>a_str;
	if(a_str.length() < 4) {
		if(a_str[0] == a_str[a_str.length()-1]) {
			return 0;
		}
	}
	else {
		if(a_str[0] == a_str[3] && a_str[1] == a_str[2]) {
			return 0;
		}
	}
	return 1;
	
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