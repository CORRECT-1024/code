#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

struct node{
	LL dis1, dis0, pos;
	bool operator < (const node & x) const{
		return min(x.dis1, x.dis0) < min(dis1, dis0);
	}
};

priority_queue<node> q;
int s;
int n, m, h;

void dijkstra(vector<node> &dis, vector<vector<pair<int, LL> > > &bian, vector<int> &a)
{
    vector<int> vis1(n+10, 0), vis2(n+10, 0);
    dis[s].dis0 = 0;
    if (a[s] )  dis[s].dis1 = 0;
	q.push(dis[s]);
	while(!q.empty()){
		node tmp=q.top();
		q.pop();
		int x=tmp.pos,d1=tmp.dis1, d0 = tmp.dis0;
		// if (vis[x])  continue;
		if (vis1[x] == 1)  vis2[x] = 1;
        else vis1[x] = 1;
        for (int i=0; i<bian[x].size(); i++) {
            int y = bian[x][i].first, len = bian[x][i].second;
            bool bo1 = false, bo2 = false;
            if (dis[y].dis0 > dis[x].dis0 + len) {
                dis[y].dis0 = dis[x].dis0 + len;
                bo1 = true;
            }
            if (dis[x].dis1 < 1e15) {
                if (dis[y].dis1 > dis[x].dis1 + len / 2) {
                    dis[y].dis1 = dis[x].dis1 + len / 2;
                    bo2 = true;
                }
            } else if (a[y] ) {
                if (dis[y].dis1 > dis[x].dis0 + len) {
                    dis[y].dis1 = dis[x].dis0 + len;
                    bo2 = true;
                }
            }
            if (bo1 && !vis1[i]) {
                q.push(dis[y]);
            } else if (bo2 && !vis2[i]) {
                q.push(dis[y]);
            }
        }
	}
}
void work() {
    cin >> n >> m >> h;
    vector<int> a(n+10, 0);
    for (int i=1; i<=h; i++) {
        int x;  cin >> x;
        a[x] = 1;
    }
    vector<vector<pair<int, LL> > > bian(n+10, vector<pair<int, LL> > ());
    for (int i=1; i<=m; i++) {
        int u, v; LL w; cin >> u >> v >> w;
        bian[u].push_back({v, w});
        bian[v].push_back({u, w});
    }
    vector<node > f1(n+10, {(LL)1e15, (LL)1e15, (LL)0}), f2(f1);
    vector<int> vis(n+10, 0);
    for (int i=1; i<=n; i++)  f1[i].pos = i, f2[i].pos = i;
    s = 1;
    dijkstra(f1, bian, a);
    s = n;
    vis = vector<int> (n+10, 0);
    dijkstra(f2, bian, a);
    LL ans = 1e15;
    for (int i=1; i<=n; i++) {
        ans = min(ans, max(min(f1[i].dis0, f1[i].dis1) , min(f2[i].dis0, f2[i].dis1) ) );
        // cout << i << ' ' << min(f1[i].dis0, f1[i].dis1) << ' ' << min(f2[i].dis0, f2[i].dis1) << '\n';
    }
    if (ans >= 1e15) ans = -1;
    cout << ans << '\n';
}
int main()
{
    #ifdef QHK
    freopen("qi.in","r",stdin);
    freopen("qi.out","w",stdout);
    #endif
    ios::sync_with_stdio(false); cin.tie(0); 
    int T=1;
    // scanf("%d",&T);
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
