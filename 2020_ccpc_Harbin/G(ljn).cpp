#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr i64 INF = 1e14;

void solve()
{
    double t, r;
    cin >> t >> r;
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, i64>>> g(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    int k;
    cin >> k;
    vector<int> a(k + 1);
    vector<double> p(k + 1);
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i] >> p[i];
        p[i] /= 100.0;
    }

    vector<vector<i64>> d(k + 2, vector<i64>(n + 1, INF));
    auto dijkstra = [&](int beg, int idx) {
        priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<>> pq;
        vector<int> vis(n + 1, false);
        vector<i64> &dist = d[idx];
        dist[beg] = 0;
        pq.emplace(0, beg);
        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (vis[u])
                continue;
            vis[u] = true;
            for (const auto [nei, w] : g[u])
            {
                if (vis[nei])
                    continue;
                if (dist[nei] > w + d)
                {
                    dist[nei] = w + d;
                    pq.emplace(dist[nei], nei);
                }
            }
        }
    };

    dijkstra(1, k + 1);
    for (int i = 1; i <= k; i++)
        dijkstra(a[i], i);

    vector<vector<double>> dp(k + 1, vector<double>(1 << k, INF));
    function<double(int, int)> dfs = [&](int idx, int used) -> double {
        if (dp[idx][used] != INF)
            return dp[idx][used];

        double ans = 0;
        ans += (1.0 - p[idx]) * (double)d[idx][n] / r;
        double mn = (double)d[idx][n] / t;
        for (int i = 1; i <= k; i++)
        {
            if ((used >> (i - 1)) & 1)
                continue;
            mn = (double)d[idx][a[i]] / t + dfs(i, used | (1 << (i - 1)));
        }
        ans += mn * p[idx];
        return dp[idx][used] = ans;
    };

    double ans = (double)d[k + 1][n] / t;
    for (int i = 1; i <= k; i++)
        ans = min(ans, (double)d[i][1] / t + dfs(i, 1 << (i - 1)));

    if (ans > 1e9)
    {
        cout << -1 << "\n";
        return;
    }
    cout.precision(9);
    cout.setf(ios::fixed);
    cout << ans << "\n";
}

int main()
{
#ifdef QHK
    freopen("qi.in", "r", stdin);
    freopen("qi.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}