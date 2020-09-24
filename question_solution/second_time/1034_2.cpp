// 二叉树的后序遍历：根据一个二叉树的前序遍历和中序遍历，求出后序遍历
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int n, ss;
char a[1100], b[1100], c[1100];

void dfs(int al, int ar, int bl, int br) {
    if(al>ar) {
        return ;
    }
    int lc = 0;
    for(int i = bl; i <= br; i++) {  // 寻找根节点
        if(a[al] == b[i]) {
            lc = i-bl;
            break;
        }
    }
    dfs(al+1, al+lc, bl, bl+lc-1);  // 遍历左孩子
    dfs(al+lc+1, ar, bl+lc+1, br);  // 遍历右孩子
    c[++ss] = a[al];
}

int main() {
    scanf("%s%s", a+1, b+1); // 数组名+1：传递的是数组元素大小的字节数  数组名地址+1：传递的是整个数组大小的字节数
    n = strlen(a+1); // 注意strlen的用法
    dfs(1, n, 1, n);
    printf("%s", c+1);  // KNOWLEDGE POINT: char数组可以通过传递a+1的方式进行打印，并且读入的时候可以用&n[i]（打印不行）
}

// 关于char类数组用法：
// *(*(&array+1)-1)里，
// &array是取array的地址；
// &array+1就是在array的地址的基础上向前跑4*5个字节；
// *(&array+1)就是在数组末尾再往后一个字节的地址；
// *(&array+1)-1就是数组末尾的地址；
// *(*(&array+1)-1)就是数组末尾的那个元素。