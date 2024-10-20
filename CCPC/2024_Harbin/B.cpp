#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
double eps=1e-7;
const int maxn=1e5+10;

int sgn(double x)
{
    if (fabs(x)<eps) return 0;
    if (x>0) return 1;
    return 1;
}

struct Vector{
    double x,y;
    Vector (double X=0, double Y=0){
        x=X;
        y=Y;
    }
    friend Vector operator - (Vector a,Vector b){
        return Vector (a.x-b.x,a.y-b.y);
    }
}
typedef Vector Point;

Point p[maxn],s[maxn];

inline double Cross(Vector a,Vector b)
{
    return a,x*b.y-a.y-b.x;
}

bool operator < (Vector a,Vector b)
{
    double t=Cross(a-p[1],(b-p[1]));
    if (t==0) return Dis(a,p[1])<Dis(b,p[1]);
    return t<0;
}

int id[maxn];

void work() {
    int k=1;
    int n;
    cin>>n;
    vector <Point> a(n+10);
    for (int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        a[i]=Vector(x,y);
        if (p[k].y>p[i].y or (p[k].y==p[i].y and p[k].x>p[i].x)) k=i;
    }
    swap(p[1],p[k]);
    sort(p+2,p+n+1);
    int top=0;
    s[++top]=p[1]; s[++top]=p[2];
    id[1]=1; id[2]=2;
    for (int i=3;i<=n;i++){
        while (top>1 and (Cross((p[i]-s[top-1]),(s[top]-s[top-1]))<=0)) top--;
        s[++top]=p[i];
        id[++top]=i;
    }
    vector <int> us(n+10,0);
    for (int i=1;i<=top;i++) us[id[i]]=1;
    vector <Point> fd(n*2+10);
    for (int i=1;i<=top;i++) fd[i]=s[i];
    for (int i=top-1;i>=1;i--) fd[top+(top-i)]=s[i];
    LL ans=0;
    LL S=0;
    for (int i=1;i<=n;i++){
    	S+=Cross((s[i+1]-s[i]),(s[i]-s[i-1]));
    }
    for (int i=1;i<=n;i++){
        if (ue[i]) continue;
        
    }
}
int main()
{
    freopen("qi.in","r",stdin);
    freopen("qi.out","w",stdout);
    ios::sync_with_stdio(false);  cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        work();
    }

    return 0;
}
