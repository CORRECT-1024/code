#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Rof(i,a,b) for(int i=(a);i>=(b);i--)
#define wln putchar('\n')
#define pii pair<int,int>
#define ll long long
const int N=500005,B=19;
int n,m,q;
int fa[N],dfn[N],low[N],now,sta[N],top,col[N],ccnt;
int ind[N];
ll dis[N];
bool insta[N],f[N],ff[N];
vector<pii> e[N];
vector<int> e2[N];
void tarjan(int x)
{
    // printf("tarjan:%d\n",x);
    dfn[x]=low[x]=++now;
    sta[++top]=x;
    insta[x]=1;
    for(auto [y,z]:e[x])
        if(!dfn[y])
        {
            fa[y]=x;
            dis[y]=dis[x]+z;
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if(insta[y])
        {
            low[x]=min(low[x],dfn[y]);
            // printf("x=%d(%lld),y=%d(%lld),z=%d\n",x,dis[x],y,dis[y],z);
            if(dis[x]-dis[y]+z!=0)f[x]=1;
        }
    // printf("tarjan(%d):%d %d\n",x,dfn[x],low[x]);
    if(low[x]==dfn[x])
    {
        col[x]=++ccnt;
        while(sta[top]!=x)
        {
            int y=sta[top];
            col[y]=ccnt;
            insta[y]=0;
            ff[ccnt]|=f[y];
            top--;
        }
        insta[x]=0;
        ff[ccnt]|=f[x];
        top--;
    }
}
int main()
{
    #ifdef QHK
    freopen("qi.in","r",stdin);
    freopen("baoli.txt","w",stdout);
    #endif
    scanf("%d%d%d",&n,&m,&q);
    For(i,1,m)
    {
        int x,y,z;
        scanf("%d%d",&x,&z);
        y=x+z;
        x=(x%n+n)%n;
        y=(y%n+n)%n;
        e[x].push_back({y,z});
    }
    For(i,0,n-1)
        if(!dfn[i])tarjan(i);
    // For(i,0,n-1)printf("%d ",col[i]); wln;
    // For(i,1,ccnt)printf("%d ",(int)ff[i]); wln;
    For(i,0,n-1)
        for(auto [j,k]:e[i])
        {
            int x=col[i],y=col[j];
            if(x!=y)
            {
                e2[y].push_back(x);
                ind[x]++;
            }
        }
    For(i,1,ccnt)
        if(ind[i]==0)sta[++top]=i;
    while(top)
    {
        int x=sta[top]; top--;
        for(int y:e2[x])
        {
            ff[y]|=ff[x];
            ind[y]--;
            if(ind[y]==0)sta[++top]=y;
        }
    }
    For(i,1,q)
    {
        int x;
        scanf("%d",&x);
        x=(x%n+n)%n;
        if(ff[col[x]])printf("Yes\n");
        else printf("No\n");
    }
}