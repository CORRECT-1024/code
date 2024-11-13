#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void fun(int a, int last, int &now) {
    if (a == last) now = last;
    if (a > last) now = last + 1;
    if (a < last) now = last - 1;
}
void work() {
    int n;
    cin >> n;
    vector<int> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    vector<array<int, 3> > dp(n+10, {0, (int)-1e9, (int)-1e9});
    for (int i=1; i<=n; i++) {
        fun(a[i], dp[i-1][0], dp[i][0]);
        fun(a[i], dp[i-1][2], dp[i][2]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0]);
        int dpi2;
        fun(a[i], dp[i-1][1], dpi2);
        dp[i][2] = max(dp[i][2], dpi2);
        // cout << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << '\n';
    }
    int ans = max(dp[n][1], dp[n][2]);
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
    while(T--) {
        work();
    }

   return 0;
}
