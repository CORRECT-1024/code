#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL n, m, v;
    cin >> n >> m >> v;
    vector<LL> a(n+10, 0), sum(n+10, 0), d1(n+10, 0), d2(n+10, 0);
    LL fsum = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
        fsum += a[i];
        if (fsum >= v) {
            fsum = 0;
            d1[i] = d1[i-1] + 1;
        } else {
            d1[i] = d1[i-1];
        }
    }
    fsum = 0;
    for (int i=n; i>=1; i--) {
        fsum += a[i];
        if (fsum >= v) {
            fsum = 0;
            d2[i] = d2[i+1] + 1;
        } else {
            d2[i] = d2[i+1];
        }
    }
    LL ans = -1;
    int r = 0;
    for (int i=0; i<=n; i++) {
        while (r <= n && d2[r + 1] + d1[i] >= m) r ++;
        if (r > i) ans = max(ans, sum[r-1] - sum[i]);
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
    while(T--) {
        work();
    }

   return 0;
}
