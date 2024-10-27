#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, m;
    cin >> n >> m;
    vector<LL> a(n+10, 0), b(m+10, 0);
    for (int i=1; i<=n; i++)  cin >> a[i];
    vector<LL> sum(n+10, 0);
    for (int i=1; i<=n; i++) {
        sum[i] = sum[i-1] + a[i];
    }
    for (int i=1; i<=m; i++)  cin >> b[i];
    vector<vector<LL> > dp(n+10, vector<LL> (m+10, 1e18));
    for (int i=1; i<=m; i++)  dp[0][i] = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            dp[i-1][j] = min(dp[i-1][j], dp[i-1][j-1]);
        }
        if (b[1] < a[i]) {
            cout << -1 << '\n';
            return;
        }
        int l = 1, r = m;
        while (l < r) {
            int mid = ((l + r + 1) >> 1);
            if (b[mid] >= a[i]) l = mid;
            else r = mid - 1;
        }
        for (int j=1; j<=l; j++) {
            int l = i, r = n;
            while (l < r) {
                int mid = ((l + r + 1) >> 1);
                if (sum[mid] - sum[i-1] <= b[j]) l = mid;
                else r = mid - 1;
            }
            dp[r][j] = min(dp[r][j], dp[i-1][j] + m - j);
        }
    }
    LL ans = 1e18;
    for (int i=1; i<=m; i++) {
        ans = min(ans, dp[n][i]);
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
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
