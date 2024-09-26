#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 2> > a(m+10);
    vector<int> bo(n+10, 0);
    for (int i=1; i<=m; i++) {
        cin >> a[i][0] >> a[i][1];
        bo[a[i][0]] = 1;
        bo[a[i][1]] = 2;
    }
    vector<vector<LL> > dp(n+10, vector<LL> (n+10, 0));
    dp[0][0] = 0;
    int p = 0;
    for (int i=1; i<=n; i++) {
        if (bo[i] == 1) {
            for (int j=0; j<=p; j++) {
                dp[i][j] = dp[i-1][j] + j;
            }
        } else if (bo[i] == 2) {
            for (int j=0; j<=p; j++) {
                dp[i][j+1] = dp[i-1][j];
            }
            p ++;
        } else {
            for (int j=0; j<=p; j++) {
                dp[i][j] = dp[i-1][j] + j;
                dp[i][j + 1] += dp[i-1][j];
            }
            p ++;
        }
    }
    LL ans = 0;
    for (int i=m; i<=n - m; i++) {
        LL num = 0;
        if (i) num += i * (i - 1) / 2;
        if (i != n) num += (n - i) * (n - i - 1) / 2;
        num += dp[n][i];
        ans = max(ans, num);
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
