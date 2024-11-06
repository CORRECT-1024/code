#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL n, k, ans;
    cin >> n >> k;
    vector<LL> a(n+10, 0), hsum(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    ans = a[1];
    for (int i=1; i<=n; i++) {
        ans = gcd(ans, a[i]);
    }
    hsum[n] = a[n];
    for (int i=n-1; i>=1; i--) {
        hsum[i] = gcd(a[i], hsum[i+1]);
    }
    vector<int> bo(n+10, 0);
    bo[1] = 1;  bo[n] = 1;
    LL p = a[1], pp = a[1] + k;
    for (int i=2; i<=n; i++) {
        if (gcd(p, a[i]) != p) {
            bo[i] = 1;  p = gcd(p, a[i]);
        }
        if (gcd(pp, a[i] + k) != pp) {
            bo[i] = 1;  pp = gcd(pp, a[i] + k);
        }
    }
    p = a[n];  pp = a[n] + k;
    for (int i=n-1; i>=1; i--) {
        if (gcd(p, a[i]) != p) {
            bo[i] = 1;  p = gcd(p, a[i]);
        }
        if (gcd(pp, a[i] + k) != pp) {
            bo[i] = 1;  pp = gcd(pp, a[i] + k);
        }
    }
    //{l, gcd(sum_l-1, fsum_lr)}
    vector<array<LL, 2> > dp;
    // i : r
    LL sum = a[1];
    for (int i=1; i<=n; i++) {
        for (auto &[l, num] : dp) {
            num = gcd(num, a[i] + k);
        }
        if (bo[i]) {
            if (i == 1)  dp.push_back({i, a[i] + k});
            else dp.push_back({i, gcd(sum, a[i] + k)});
        }
        vector<array<LL, 2> > fdp;
        for (int j=0; j<dp.size(); j++) {
            if (j == 0) {
                fdp.push_back(dp[j]);
            } else if (dp[j][1] != dp[j-1][1]) {
                fdp.push_back(dp[j]);
            }
            if (i < n) ans = max(ans, gcd(hsum[i + 1], dp[j][1]));
            else ans = max(ans, dp[j][1]);
        }
        swap(dp, fdp);
        sum = gcd(sum, a[i]);
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
