#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void dijkstra(int s, vector<vector<long long>> &d, vector<vector<pair<int,long long>>> &graph, vector<int> &hs){
    auto cmp = [&](auto &a, auto &b){return make_pair(d[a.first][a.second],a) < make_pair(d[b.first][b.second],b);};
    set<pair<int,int>,decltype(cmp)> q(cmp);
    
    d[s][0] = 0;
    q.insert({s,0});

    while (q.size()){
        auto [curv,curh] = *q.begin();
        q.erase(q.begin());

        bool horse = (curh || hs[curv]);
        for (auto &[neighv, neighd] : graph[curv]){
            long long dist = horse?neighd/2:neighd;
            if (d[neighv][horse] > d[curv][curh] + dist){
                q.erase({neighv,horse});
                d[neighv][horse] = d[curv][curh] + dist;
                q.insert({neighv,horse});
            }
        }
    }
}
void work() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> hs(n+10, 0);
    for (int i=1; i<=k; i++) {
        int x;  cin >> x;
        hs[x] = 1;
    }
    vector<vector<pair<int, LL> > > bian(n+10, vector<pair<int, LL> > ());
    for (int i=1; i<=m; i++) {
        int u, v;  LL w;
        cin >> u >> v >> w;
        bian[u].push_back({v, w});
        bian[v].push_back({u, w});
    }
    vector<vector<LL> > d1(n+10, vector<LL> (2, 1e15)), dn(d1);
    dijkstra(1, d1, bian, hs);
    dijkstra(n, dn, bian, hs);
    LL ans = 2e15;
    for (int i=1; i<=n; i++) {
        d1[i][0] = min(d1[i][0], d1[i][1]);
        dn[i][0] = min(dn[i][1], dn[i][0]);
        ans = min(ans, max(d1[i][0], dn[i][0]));
    }
    if (ans >= 1e15) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
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
