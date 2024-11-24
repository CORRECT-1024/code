//读错题了，sad
//简单但麻烦的dp，不想写
// 妈的，场场秒出思路但是实现不出来，还不练码力呢
// 就这题都能又wa2发，现在码力实在是太弱了
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    for (auto &c : s1) {
        if (c == 'A') c = 1;
        else c = 0;
    }
    for (auto &c : s2) {
        if (c == 'A') c = 1;
        else c = 0;
    }
    s1 = " " + s1;
    s2 = " " + s2;
    vector<array<LL, 3> > dp(n+10, {(LL)-1e9, (LL)-1e9, (LL)-1e9});
    dp[1][0] = 0;
    for (int i=1; i<=n; i++) {
        // cout << i << '\n';
        // cout << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << '\n';
        if (i + 3 <= n + 1) {
            int d = (s1[i] + s1[i+1] + s1[i+2]) / 2;
            d += (s2[i] + s2[i+1] + s2[i+2]) / 2;
            dp[i+3][0] = max(dp[i+3][0], dp[i][0] + d);
            if (i + 3 <= n) {
                d = (s1[i] + s1[i+1] + s1[i+2]) / 2;
                d += (s2[i+3] + s2[i+1] + s2[i+2]) / 2;
                dp[i+3][2] = max(dp[i+3][2], dp[i][2] + d);
            }
            d = (s1[i+3] + s1[i+1] + s1[i+2]) / 2;
            d += (s2[i] + s2[i+1] + s2[i+2]) / 2;
            dp[i+3][1] = max(dp[i+3][1], dp[i][1] + d);
        }
        if (i + 2 <= n + 1) {
            int d = (s1[i+1] + s2[i] + s2[i+1]) / 2;
            dp[i+2][0] = max(dp[i+2][0], dp[i][1] + d);
            d = (s1[i] + s1[i+1] + s2[i+1]) / 2;
            dp[i+2][0] = max(dp[i+2][0], dp[i][2] + d);
        }
        if (i + 1 <= n + 1) {
            int d = (s1[i] + s2[i] + s2[i+1]) / 2;
            dp[i+1][2] = max(dp[i+1][2], dp[i][0] + d);
            d = (s1[i] + s2[i] + s1[i+1]) / 2;
            dp[i+1][1] = max(dp[i+1][1], dp[i][0] + d);
        }
    }
    cout << dp[n+1][0] << '\n';
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
