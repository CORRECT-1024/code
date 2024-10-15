#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int mod = 998244353;

void work() {
    int n, m;
    cin >> n >> m;
    vector<LL> p(m+10, 0);
    p[0] = 1;
    for (int i=1; i<=m; i++) {
        for (int j=i/2; j>=1; j--) {
            p[j] += p[j-1];
            p[j] %= mod;
        }
    }
    // for (int i=0; i<=m/2; i++) {
    //     //拿几张牌，需要几张1牌，方案数
    //     cout << i << ' ' << m - 2 * i << ' ' << p[i] << '\n';
    // }
    // return;
    vector<LL> dp(m+10, 0);
    dp[0] = 1;
    for (int i=2; i<=n; i++) {
        vector<LL> fdp(m+10, 0);
        for (int d = 0; d <= m / 2; d ++) {
            //d是拿的牌数，fd是差值
            int fd = (m - d) - d;
            for (int be = 0; be <= m; be ++) {
                if (be + fd > m) break;
                fdp[be + fd] += dp[be] * p[d];
                fdp[be + fd] %= mod;
            }
        }
        swap(dp, fdp);
        // for (int i=0; i<=m; i++) {
        //     cout << dp[i] << ' ';
        // }
        // cout << '\n';
    }
    // for (int i=0; i<=m; i++) {
    //     cout << dp[i] << ' ';
    // }
    // cout << '\n';
    LL ans = 0;
    vector<LL> q(m+10, 0);
    q[0] = 1;
    for (int i=0; i<=m; i++) {
        //i:差值  fid：拿几张
        // cout << i << ": ";
        if ((m - i) % 2) continue;
        int fid = i + (m - i) / 2;
        q = vector<LL> (m+10, 0);
        q[0] = 1;
        for (int j=1; j<=m; j++) {
            for (int l = j; l>=1; l--) {
                if (l - i <= j - l) {
                    q[l] += q[l - 1];
                    q[l] %= mod;
                }
            }
        }
        // cout << i << ":\n";
        // cout << fid << '\n';
        // for (int j=0; j<=m; j++) {
        //     cout << q[j] << ' ';
        // }
        // cout << '\n';
        // cout << dp[i] << ' ' << q[fid] << '\n';
        ans = (ans + dp[i] * q[fid] % mod) % mod;
    }
    // cout << '\n';
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
