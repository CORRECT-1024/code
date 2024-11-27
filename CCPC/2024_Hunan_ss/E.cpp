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
        a[i] --;
    }
    vector<array<int, 2> > dp(1<<18, {-1, -1});
    for (int i=1; i<=n; i++) {
        int p = 0;
        for (int r = i; r <= n; r ++) {
            if (p & (1 << a[r]) )  break;
            p |= (1 << a[r]);
            if (dp[p][0] == -1)  dp[p][0] = i;
            else dp[p][0] = max(dp[p][0], i);
            if (dp[p][1] == -1)  dp[p][1] = r;
            else dp[p][1] = min(dp[p][1], r);
            // cout << p << ": " << i << ' ' << r << '\n';
        }
    }
    dp[0] = {n + 1, -1};
    vector<array<int, 20> > fdp(1 << 18, {0});
    for (int i=0; i<(1 << 18); i++) {
        fdp[i][0] = n + 1;
        int ylen = 0, ii = i;
        while (ii ) {
            if (ii & 1)  ylen ++;
            ii >>= 1;
        }
        if (dp[i][0] != -1)  fdp[i][ylen] = max(fdp[i][ylen], dp[i][0]);
        for (int j=0; j<18; j++) {
            if (i & (1 << j ) )  continue;
            int to = i | (1 << j);
            for (int k = 1; k<=18; k++) {
                fdp[to][k] = max(fdp[to][k], fdp[i][k]);
            }
        }
    }
    int ans = 0;
    for (int i=0; i<(1 << 18); i++) {
        if (dp[i][0] == -1 || dp[i][1] == -1)  continue;
        int ylen = 0, ii = i;
        while (ii ) {
            if (ii & 1)  ylen ++;
            ii >>= 1;
        }
        int f = ((1 << 18) - 1) - i;
        for (int k=0; k<=18; k++) {
            if (fdp[f][k] > dp[i][1]) {
                // cout << ylen << ' ' << k << '\n';
                ans = max(ans, ylen + k);
            }
        }
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
    while(T--) {
        work();
    }

   return 0;
}
