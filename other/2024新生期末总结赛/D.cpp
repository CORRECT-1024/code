#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    vector<LL> a(10, 0);
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(&a[0], &a[4]);
    vector<array<LL, 2> > dp((1 << 10), {(LL)1e16, (LL)1e16});
    dp[0][0] = 0;
    for (int i=0; i<(1 << 4); i++) {
        int p = 0, q = i;
        // cout << dp[i][0] << ' ' << dp[i][1] << '\n';
        if (i == 0) {
            for (int j=0; j<4; j++) {
                for (int k=0; k<j; k++) {
                    int t = (1 << j) + (1 << k);
                    if (q & t)  continue;
                    dp[q | t][1] = min(dp[q | t][1], dp[q][0] + max(a[j], a[k]) );
                    // cout << "**" << (q | t) << ' ' << max(a[j], a[k]);
                }
            }
        }
        for (int ii = 0; ii<4; ii++) {
            int ft = (1 << ii);
            if (q & ft) {
                int qq = q - ft;
                dp[qq][0] = min(dp[qq][0], dp[q][1] + a[ii]);
                for (int j=0; j<4; j++) {
                    for (int k=0; k<j; k++) {
                        int t = (1 << j) + (1 << k);
                        if (qq & t)  continue;
                        dp[qq | t][1] = min(dp[qq | t][1], dp[qq][0] + max(a[j], a[k]) );
                    }
                }
            }
        }
    }
    cout << dp[15][1] << '\n';
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
