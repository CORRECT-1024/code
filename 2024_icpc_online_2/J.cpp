#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

bool cmp(array<LL, 3> x, array<LL, 3> y) {
    return x[2]*y[0] > y[2]*x[0];
}
void work() {
    int n;
    cin >> n;
    LL sumc = 0, ans = 0;
    vector<array<LL, 3> > a(n+10, {0, 0, 0});
    for (int i=1; i<=n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        ans += a[i][1];
    }
    sort(&a[1], &a[n+1], cmp);
    for (int i=1; i<=n; i++) {
        ans -= sumc * a[i][0];
        sumc += a[i][2];
    }
    cout << ans << '\n';
}
int main()
{
    #ifdef QHK
    freopen("qi.in","r",stdin);
    freopen("qi.out","w",stdout);
    #endif
    ios::sync_with_stdio(false);  cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        work();
    }

    return 0;
}