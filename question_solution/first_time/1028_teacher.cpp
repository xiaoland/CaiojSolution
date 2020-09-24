#include<cstdio>
#include<cmath>
using namespace std;
 
int main()
{
    int A,B,c;scanf("%d%d",&A,&B);
    for(int a=A;a<=B;a++)
    {
        for(int b=a;b<=B;b++)
        {
            int cc=a*a+b*b;
            c=sqrt(cc);
         
            if( c*c == cc && c<=B )   // KNOWLEDGE POINT: 利用c*c==cc来判断开根后是否为整数
            {
                printf("%d %d %d\n",a,b,c); 
            }
        }
    }
    return 0;
}