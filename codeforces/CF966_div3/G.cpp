//从n开始跑dij
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void dij(int x, vector<vector<array<int, 3> > >&bian, int t1, int t2, vector<int>&dis, int n) {
    for (int i=1; i<=n; i++) {
        dis[i] = 1e9;
    }
    dis[x] = 0;
    priority_queue<array<int, 2> , vector<array<int, 2> > , greater<>> pri;
    pri.push({dis[x], x});
    vector<int> bo(n+10, 0);
    while (!pri.empty() ) {
        int num = pri.top()[0], id = pri.top()[1];
        pri.pop();
        if (bo[id] ) continue;
        bo[id] = 1;
        for (int i=0; i<bian[id].size(); i++) {
            int to = bian[id][i][0];
            if (num > t2 || num + bian[id][i][1] <= t1) {  //you mei you = 
                if (num + bian[id][i][1] < dis[to]) {
                    dis[to] = num + bian[id][i][1];
                    pri.push({dis[to], to});
                }
            } else if (t2 + bian[id][i][1] <= dis[to]) {
                dis[to] = t2 + bian[id][i][1];
                pri.push({dis[to], to});
            }
            if (num + bian[id][i][2] < dis[to]) {
                dis[to] = num + bian[id][i][2];
                pri.push({dis[to], to});
            }
        }
    }
}
void work() {
    int n, m;
    cin >> n >> m;
    int t0, t1, t2;
    cin >> t0 >> t1 >> t2;
    vector<vector<array<int, 3> > > bian(n+10, vector<array<int, 3> >());
    for (int i=1; i<=m; i++) {
        int u, v, w1, w2;
        cin >> u >> v >> w1 >> w2;
        bian[u].push_back({v, w1, w2});
        bian[v].push_back({u, w1, w2});
    }
    t1 = t0 - t1;  t2 = t0 - t2;
    swap(t1, t2);
    vector<int> dis(n+10);
    dij(n, bian, t1, t2, dis, n);
    // cout << t0 << ' ' << dis[1] << ' ';
    int ans = t0 - dis[1];
    if (ans < 0) ans = -1;
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
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
