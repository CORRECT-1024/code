#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL n, m, k;
    cin >> n >> m >> k;
    vector<array<LL, 2> > a(n+10);
    for (int i=1; i<=n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    sort(&a[1], &a[n+1], [&](array<LL, 2>&x, array<LL, 2>&y) {
        return x[0] > y[0];
    });
    vector<LL> dp(m + k + 10, 0);
    for (int i=1; i<=n; i++) {
        for (int j=m + k - 1; j >= 0; j--) {
            int d = (j < k ? 1 : a[i][0]);
            if (j + d > m + k)  continue;
            dp[j + d] = max(dp[j + d], dp[j] + a[i][1]);
        }
    }
    LL ans = 0;
    for (int i=0; i<=m + k; i++) {
        ans = max(ans, dp[i]);
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
    // cin >> T;
    while(T--){
        work();
    }

   return 0;
}
