#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int r,c,n,map[60][60],ans[60][60];
char st[60][60],str[1000];
bool vis[60][60];
//vis数组是用来记录，当次search（）中ans[][]为1点，是上次serch()得来的ans[][]，
//还是由上次search()得来的ans[][]由这次search()移动得来的; 
int dx[5]={0,-1,0,1,0},dy[5]={0,0,1,0,-1};
//方向，我是左上角为原点，向下为x的正方向，想又为y的正方向； 
void search(int direct)
{
    memset(vis,0,sizeof(vis));//新的一 轮，就要重新开始 
    for(int i=1;i<=r;i++)
    for(int j=1;j<=c;j++)
    {
        if(ans[i][j] && !vis[i][j])
        {
            int ddx=i+dx[direct],ddy=j+dy[direct];
            ans[i][j]=0;//它一移动原来的位置就不在有可能在有； 
            while(map[ddx][ddy])//将其能到的点全标记； 
            {
                ans[ddx][ddy]=1;
                vis[ddx][ddy]=true;
                ddx=ddx+dx[direct];ddy=ddy+dy[direct];
            }
        }
    }
}
int main()
{
    scanf("%d %d",&r,&c);
    for(int i=1;i<=r;i++)
    {
        scanf("%s",st[i]+1);
        for(int j=1;j<=c;j++)
        {
            if(st[i][j]=='*') map[i][j]=1,ans[i][j]=1;
            //最开始的位置，就是还没移动时的可能的位置； 
            else if(st[i][j]=='.') map[i][j]=1;
            else map[i][j]=0;
        }
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",str);
        if(str[0]=='N') search(1);//向上 
        if(str[0]=='E') search(2);//向右 
        if(str[0]=='S') search(3);//向下 
        if(str[0]=='W') search(4);//向左 
    }
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            if(ans[i][j]) printf("*");
            else 
            {
                if(st[i][j]=='*') printf(".");
                else printf("%c",st[i][j]);
            }
        }
        printf("\n");
    }
}