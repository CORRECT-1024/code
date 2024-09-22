#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int mod = 998244353;

void work() {
    LL n, m, k;
    cin >> n >> m >> k;
    vector<LL> dp(n+10, 0);
    vector<pair<int, int> > to(m+10);
    vector<LL> add(m+10, 0);
    for (int i=1; i<=m; i++) {
        cin >> to[i].first >> to[i].second;
        to[i].first --;  to[i].second --;
    }
    dp[0] = 1;
    LL fn = k / n + 1;
    fn *= n;
    fn = n;
    for (int i=1; i<=k; i++) {
        for (int j=1; j<=m; j++) {
            int u = (to[j].first + fn - i % n + 1) % n;
            int v = (to[j].second + fn - i % n) % n;
            // cout << u << "->" << v << '\n';
            add[j] = dp[u];
        }
        for (int j=1; j<=m; j++) {
            int v = (to[j].second + fn - i % n) % n;
            dp[v] = (dp[v] + add[j]) % mod;
        }
        // for (int j=0; j<n; j++) {
        //     // cout << dp[(j + fn - i % n) % n] << " \n"[j == n - 1];
        //     cout << dp[j] << ' ' ;
        // }
        // cout << '\n';
    }
    LL ans = 0;
    for (int i=0; i<n; i++) {
        ans = (ans + dp[i]) % mod;
    }
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
    // cin >> T;
    while(T--){
        work();
    }

   return 0;
}
