#include <cstdio>
using namespace std;
int n;
int out[4400];

void dfs(int k) {

    if (n == 0) { 
        // 如果n被减到0了，意味着分解完毕（而又因为边生成边打印，所以不需要输出，直接退出本次递归）
        return ;
    }
    if (k > 1) {
        
        out[k] = n; // 通过这个方式，使1+6、1+1+5...出现
        if (out[k-1] <= out[k]) {
        	// 只有上一个数还没有大过这次的n才能输出 
    		for (int i = 1; i < k; i++) {
            	printf("%d+", out[i]);
        	}
        	printf("%d\n", out[k]); // 上面的只输出到第k-1个，所以在这里打印最后一个并且跳行（通用）
        }
    
    }  // ATTENTION： 没有else！没有else！没有else！！！
    for (int i = out[k-1]; i <= n; i++) {  // i从上一个数开始，保证这次生成的数大于上一个
        out[k] = i;
        n-=i; // 减掉：1、看看是否已经结束；2、实现1+6、1+1+5...的出现 
        dfs(k+1);
        out[k] = 0;  // 关系其实不大
        n+=i; // 加回去，保证上一个递归有数可加
    }

}

int main() {

    scanf("%d", &n);
    out[0] = 1; // 保证在k-1那里不出问题
    dfs(1);
    return 0;

}
