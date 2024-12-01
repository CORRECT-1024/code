#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, m;
    cin >> n >> m;
    vector<vector<LL> > a(n+10, vector<LL> (m+10)), sum(a), fsum(a);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> a[i][j];
            sum[i][j] = sum[i][j-1] + a[i][j];
        }
        for (int j=m; j>=1; j--) {
            fsum[i][j] = fsum[i][j+1] + a[i][j];
        }
    }
    vector<vector<LL> > dp(2, vector<LL> (m+10, (LL)-1e15)), fdp(dp);
    for (int i=1; i<m; i++) {
        dp[0][i] = 0;
        fdp[0][i+1] = 0;
    }
    for (int i=1; i<=n; i++) {
        dp[i % 2] = vector<LL> (m+10, (LL)-1e15);
        fdp[i % 2] = vector<LL> (m+10, (LL)-1e15);
        vector<LL> masum(m+10, (LL)-1e15);
        for (int j=m; j>=1; j--) {
            // sum > j - 1
            masum[j] = max(masum[j+1], sum[i][j]);
        }
        for (int j=m-1; j>=1; j--) {
            dp[i%2][j] = max({dp[i%2][j+1], fdp[(i+1)%2][j] + masum[j+1], dp[(i+1)%2][j+1] + masum[j+1]});
            // cout << fdp[(i+1)%2][j] << ' ' << masum[j+1] << '\n';
        }
        for (int j=m-1; j>=1; j--) {
            dp[i%2][j] -= sum[i][j-1];
        }
        vector<LL> misum(m+10, 0);
        for (int j=1; j<=m; j++) {
            misum[j] = min(misum[j-1], sum[i][j]);
            // misum[j] = min(misum[j-1], fsum[i][j]);
        }
        for (int j=2; j<=m; j++) {
            fdp[i%2][j] = max({fdp[i%2][j-1], dp[(i+1)%2][j] - misum[j-2], fdp[(i+1)%2][j-1] - misum[j-2]});
            // cout << dp[(i+1)%2][j] << ' ' << misum[j-1] << '\n';
        }
        for (int j=2; j<=m; j++) {
            // cout << fdp[i%2][j] << ' ' << sum[i][j] << '\n';
            fdp[i%2][j] += sum[i][j];
        }
        if (i == 1) {
            for (int j=1; j<m; j++) dp[i%2][j] = max(dp[i%2][j], a[i][j]);
            for (int j=2; j<=m; j++) fdp[i%2][j] = max(fdp[i%2][j], a[i][j]);
            dp[i%2][m] = a[i][m];   fdp[i%2][1] = a[i][1];
        }
        // for (int j=1; j<=m; j++)  cout << dp[i%2][j] << ' ';
        // cout << '\n';
        // for (int j=1; j<=m; j++)  cout << fdp[i%2][j] << ' ';
        // cout << "\n\n";
    }
    LL ans = (LL)-1e15;
    for (int i=1; i<m; i++) {
        ans = max({ans, dp[n%2][i], fdp[n%2][i+1]});
        // cout << dp[n%2][i] << ' ' << fdp[n%2][i+1] << '\n';
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
