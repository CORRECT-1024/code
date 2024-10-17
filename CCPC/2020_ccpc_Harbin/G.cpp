#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void fundij(int be, vector<int>&dij, vector<vector<array<int, 2> > > &bian, int n) {
    dij[be] = 0;
    priority_queue<array<int, 2> , vector<array<int, 2> > , greater<>> pri;
    pri.push({0, be});
    vector<int> bo(n+10, 0);
    while (!pri.empty() ) {
        int num = pri.top()[0], id = pri.top()[1];
        pri.pop();
        if (bo[id] ) continue;
        bo[id] = 1;
        for (int i=0; i<bian[id].size(); i++) {
            int to = bian[id][i][0];
            if (dij[to] > num + bian[id][i][1]) {
                dij[to] = num + bian[id][i][1];
                pri.push({dij[to], to});
            }
        }
    }
}
void work() {
    double t, r;
    cin >> t >> r;
    int n, m;
    cin >> n >> m;
    vector<vector<array<int, 2> > > bian(n+10, vector<array<int, 2> > ());
    for (int i=1; i<=m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        bian[u].push_back({v, w});
        bian[v].push_back({u, w});
    }
    int k;  cin >> k;
    vector<int> id(k+10, 0);
    vector<double> p(k+10, 0);
    for (int i=1; i<=k; i++) {
        cin >> id[i] >> p[i];
        p[i] /= 100;
    }
    id[0] = 1;
    vector<vector<int> > dij(k+10, vector<int> (n+10, 1e9+1));
    for (int i=0; i<=k; i++) {
        fundij(id[i], dij[i], bian, n);
    }
    if (dij[0][n] == 1e9 + 1) {
        cout << -1 << '\n';
        return;
    }
    vector<vector<double> > dp(1 << k, vector<double> (k+10, 1e9));
    dp[0][0] = 0;
    for (int i=1; i<=k; i++) {
        // dp[1 << (i - 1)][i] = p[i] * dij[i][n] / t + (1 - p[i]) * dij[i][n] / r;
        dp[1 << (i - 1)][i] = dij[i][n] / t;
        // cout << i << dp[1 << (i-1)][i] << '\n';
    }
    double ans = dij[0][n] / t;
    vector<int> qu(k+10, 0);  int quid = 1;
    for (int bit=1; bit < (1 << k); bit ++) {
        quid = 1;
        for (int j=1; j<=k; j++) {
            if (bit & (1 << (j - 1)) ) {
                qu[quid] = j;  quid ++;
            }
        }
        for (int i=1; i<quid; i++) {
            int id1 = qu[i];
            for (int j=1; j<quid; j++) {
                int id2 = qu[j];
                if (i == j)  continue;
                dp[bit][id1] = min(dp[bit][id1], dp[bit ^ (1 << (id1 - 1))][id2] + dij[id1][id[id2]] / t);
            }
            dp[bit][id1] = p[id1] * dp[bit][id1] + (1 - p[id1]) * dij[id1][n] / r;
            ans = min(ans, dij[0][id[id1]] / t + dp[bit][id1]);
            // cout << bit << ' ' << id1 << ' ' << dp[bit][id1] << '\n';
        }
    }
    cout.precision(9);
    cout.setf(ios::fixed);
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
    // cin >> T;
    while(T--){
        work();
    }

   return 0;
}
