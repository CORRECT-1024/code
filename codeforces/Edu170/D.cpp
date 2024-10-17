#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    vector<int> dp(m+10, 0), d(m+10, 0);
    int num = 0;
    for (int i=1; i<=n; i++) {
        if (a[i] == 0) {
            num ++;
            for (int i=0; i<=num; i++) {
                if (i ) d[i] += d[i-1];
                dp[i] += d[i];
                // cout << d[i] << ' ';
            }
            // cout << '\n';
            for (int i=0; i<=num+1; i++)  d[i] = 0;
            for (int i=num; i>=1; i--) {
                dp[i] = max(dp[i], dp[i-1]);
            }
        } else if (a[i] > 0) {
            int be = a[i];
            if (be <= num ) {d[be] ++; d[num+1] --;}
            // for (int i=be; i<=num; i++) {
            //     dp[i] ++;
            // }
        } else {
            int en = num - abs(a[i]);
            if (en >= 0 ) {d[0] ++;  d[en+1] --;}
            // for (int i=0; i<=en; i++) {
            //     dp[i] ++;
            // }
        }
    }
    for (int i=0; i<=num; i++) {
        if (i ) d[i] += d[i-1];
        dp[i] += d[i];
        // cout << d[i] << ' ';
    }
    // cout << '\n';
    for (int i=0; i<=num+1; i++)  d[i] = 0;
    for (int i=num; i>=1; i--) {
        dp[i] = max(dp[i], dp[i-1]);
    }
    int ans = 0;
    for (int i=0; i<=m; i++) {
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
