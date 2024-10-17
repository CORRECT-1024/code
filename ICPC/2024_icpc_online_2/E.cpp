#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void work() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<vector<int> > bian(n+10, vector<int>());
    for (int i=1; i<=m; i++) {
        int u, v;  cin >> u >> v;
        bian[u].push_back(v);
        bian[v].push_back(u);
    }
    int k;  cin >> k;
    vector<int> s(k+10, 0);
    for (int i=1; i<=k; i++) {
        cin >> s[i];
    }


    vector<vector<int>> blk(n + 1, vector<int>(2));
    vector<vector<int>> vis(n + 1, vector<int>(2));
    queue<pair<int,int>> q;
    for (int i = 1; i <= n; i ++) {
        q.push({s[i], 0});
    }
    while(!q.empty()) {
        auto frt = q.front();
        q.pop();
        int step = frt.second;
        int node = frt.first;
        if(vis[node][step&1]) continue;
        vis[node][step&1] = 1;
        blk[node][step&1] = step;
        for (int nei:bian[node]) {
            q.push({nei, step+1});
        }
    }

    for (int i = 1; i <= n; i ++)
        blk[i][1] = min(blk[i][1], d);
    for (int i = 1; i <= n; i++)
        blk[i][0] = min(blk[i][0], d);

    vector<int> dist(n+1);
    vector<int> past(n+1);
    fill(dist.begin(), dist.end(), 1e7);
    dist[1] = 0;
    vector<int> sure(n + 1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    while(!pq.empty()) {
        auto frt = pq.top(); pq.pop();
        int node = frt.second;
        if (sure[node]) continue;
        sure[node] = 1;
        for (int nei:bian[node]) {
            if (sure[node]) continue;
            int mystp = dist[node] + 1;
            if (blk[nei][mystp & 1] <= mystp)  continue;
            if (dist[nei] > dist[node] + 1) {
                dist[nei] = dist[node] + 1;
                past[nei] = node;
                pq.push({dist[nei],nei});
            }
        }
    }

    if (dist[n] == 1e7)
        cout << "-1\n";
    else {
        cout << dist[n] << "\n";
        cout << n << " ";
        int node = n;
        while (node != 1) {
            node = past[node];
            cout << node << " ";
        }
        cout << "\n";
    }
}
int main()
{
    #ifdef QHK
    freopen("qi.in","r",stdin);
    freopen("qi.out","w",stdout);
    #endif
    ios::sync_with_stdio(false);  cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        work();
    }

    return 0;
}