#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL n, m;
    cin >> n >> m;
    vector<array<LL, 3> > a(n+10, {0, 0, 0});
    for (int i=1; i<=n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    LL fans = 0;
    for (int i=1; i<=n; i++) {
        fans += a[i][0] * a[i][1];
        m -= a[i][1];
    }
    LL ans = fans;
    sort(&a[1], &a[n+1], [&](array<LL, 3> &x, array<LL, 3> &y) {
        return x[0] > y[0];
    });
    vector<LL> sum(n+10, 0), fsum(n+10, 0);
    for (int i=1; i<=n; i++) {
        sum[i] = sum[i-1] + a[i][2] - a[i][1];
        fsum[i] = fsum[i-1] + (a[i][2] - a[i][1]) * a[i][0];
    }
    for (int i=1; i<=n; i++) {
        LL ffans = fans - a[i][0] * a[i][1];
        LL fm = m + a[i][1];
        int l = 0, r = n;
        while (l < r) {
            int mid = ((l + r + 1) >> 1);
            if (sum[mid] <= fm) l = mid;
            else r = mid - 1;
        }
        l = min(l, i - 1);
        ffans += fsum[l];
        ffans += (fm - sum[l]) * a[l + 1][0];
        ans = max(ans, ffans);
    }
    cout << ans << '\n';
}
int main()
{
    freopen("qi.in","r",stdin);
    freopen("qi.out","w",stdout);
    ios::sync_with_stdio(false);  cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        work();
    }

    return 0;
}