#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<int> a(n+10, 0);
    vector<vector<array<int, 1010> > > dp(2, vector<array<int, 1010> >(2, array<int, 1010>{(int)-1e9}));
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<=1; i++) {
        for (int j=0; j<=1000; j++) {
            for (int k=0; k<=1; k++) {
                dp[i][k][j] = -1e9;
            }
        }
    }
    dp[0][0][0] = 0;
    int mx = 0;
    int ans = 0;
    for (int i=1; i<=n; i++) {
        int p = i % 2, q = (i - 1) % 2;
        for (int j=0; j<=mx; j++) {
            dp[p][0][j] = -1e9;
            dp[p][1][j] = -1e9;
        }
        for (int j=0; j<=mx; j++) {
            if (dp[q][0][j] == -1e9 && dp[q][1][j] == -1e9)  continue;
            dp[p][0][j] = max(dp[q][0][j], dp[q][1][j]);
            int k = max(a[i], j);
            int d = a[i] > j ? a[i] - j : 0;
            int dpq0k = dp[q][0][k] != -1e9 ? dp[q][0][k] + 1 : -1e9;
            int dpq0j = dp[q][0][j] != -1e9 ? dp[q][0][j] + d + 1 : -1e9;
            dp[p][1][k] = max({dp[p][1][k], dpq0k, dpq0j});
            ans = max({ans, dp[p][0][j], dp[p][1][k]});
        }
        mx = max(mx, a[i]);
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
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
