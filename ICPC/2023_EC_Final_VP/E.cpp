#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL n, d, sum = 0;
    cin >> n >> d;
    vector<LL> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(&a[1], &a[n+1]);
    if (d == 1) {
        cout << sum * (sum - 1) / 2 << '\n';
        return;
    }
    if (d == 2) {
        LL ans = sum * (sum - 1) / 2;
        for (int i=1; i<=n; i++) {
            ans -= a[i] * (a[i]-1) / 2;
        }
        cout << ans << '\n';
        return;
    }
    LL ans = 0, p = 0;
    for (int i=1; i<=n; i++) {
        if (a[i] == p)  continue;
        LL fp = a[i] - p;
        ans += fp * (n - i + 1) * (n - i) / 2;
        p = a[i];
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
