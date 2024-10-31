#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<int> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    vector<array<int, 2> > dp(n+10, {(int)1e9, (int)1e9});
    dp[1][0] = 0;  dp[1][1] = 0;
    int ans = 0;
    for (int i=2; i<=(n)/2; i++) {
        int d = 0;
        if (a[i] == a[i-1]) d ++;
        if (a[n - i + 1] == a[n - i + 2]) d ++;
        dp[i][0] = min(dp[i][0], dp[i-1][0] + d);
        dp[i][1] = min(dp[i][1], dp[i-1][1] + d);
        d = 0;
        if (a[i] == a[n-i+2]) d ++;
        if (a[n-i+1] == a[i-1]) d ++;
        dp[i][1] = min(dp[i][1], dp[i-1][0] + d);
        dp[i][0] = min(dp[i][0], dp[i-1][1] + d);
        if (i == (n) / 2) ans = min(dp[i][1], dp[i][0]);
    }
    if (n & 1) {
        ans += (a[(n+1)/2] == a[(n+1)/2-1]) + (a[(n+1)/2] == a[(n+1)/2+1]);
    } else {
        ans += (a[n/2] == a[n/2 + 1]);
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
