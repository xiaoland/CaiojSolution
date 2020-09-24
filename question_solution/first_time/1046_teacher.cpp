#include<cstdio>
#include<cstring>
using namespace std;
struct node
{
    int a[4][4],dep,x,y;
};
node list[410000];
 
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
 
bool v[410000];
 
int d[10];
int kangtuo(node no)
{
    int b[10],len=0;
    for(int i=1;i<=3;i++)for(int j=1;j<=3;j++) b[++len]=no.a[i][j]+1;
    int ss=0;
    bool bo[10];memset(bo,false,sizeof(bo));
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<b[i];j++) if( bo[ j ]==false) ss+= d[9-i];
        bo[ b[i] ]=true;
    }
    return ss+1;
}
 
int main()
{
    d[0]=1;for(int i=1;i<=8;i++)d[i]=i*d[i-1];
    memset(v,false,sizeof(v));
     
    for(int i=1;i<=3;i++)
         for(int j=1;j<=3;j++)
         {
            scanf("%d",&list[1].a[i][j]);
            if(list[1].a[i][j]==0)
            {
                list[1].x=i;
                list[1].y=j;
            }
         }
    list[1].dep=1;
    v[ kangtuo(list[1]) ]=true;
     
    for(int i=1;i<=3;i++) for(int j=1;j<=3;j++) scanf("%d",&list[0].a[i][j]);
    int mb=kangtuo(list[0]);
    
    if( kangtuo(list[1])==mb ) { printf("1\n");return 0;}
     
    bool bk=false;
    int head,tail;head=tail=1;
    while(head<=tail)
    {
        for(int i=0;i<=3;i++)
        {
            node tno=list[head];
            int x1,y1,x2,y2;
            x1=list[head].x; y1=list[head].y;
            x2=x1+dx[i];
            y2=y1+dy[i];
            if(1<=x2&& x2<=3&& 1<=y2 && y2<=3)
            {
                int t=tno.a[x1][y1]; tno.a[x1][y1]=tno.a[x2][y2];tno.a[x2][y2]=t;
                tno.dep++;
                tno.x=x2;tno.y=y2;
                int kt=kangtuo(tno);
                if( v[ kt ]==false)
                {
                    v[ kt ]= true;
                    list[++tail]=tno;
                    if( mb==kt ) 
                    {
                        bk=true;
                        break;
                    }
                }   
            }
        }
        if(bk==true) break;
        head++; 
    }
    printf("%d\n",list[tail].dep);
    return 0;
}