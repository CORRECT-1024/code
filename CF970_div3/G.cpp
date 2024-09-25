#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL n, k;
    cin >> n >> k;
    vector<LL> a(n+10, 0);
    LL t = -1;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if (i == 1)  t = a[i];
        else t = __gcd(t, a[i]);
    }
    if (n == 1) {
        if (a[1] < k) {
            cout << k << '\n';
        } else {
            cout << k - 1 << '\n';
        }
        return;
    }
    // cout << t << ' ';
    if ((t - 1) * (n - 1) >= k) {
        LL ans = 0;
        LL d = (k - 1) / (t - 1);
        ans = t * d + k - (t - 1) * d;
        cout << ans << '\n';
    } else {
        LL ans = 0;
        ans = t * (n - 1) + k - (t - 1) * (n - 1);
        cout << ans << '\n';
    }
}
int main()
{
    #ifdef QHK
    freopen("qi.in","r",stdin);
    freopen("qi.out","w",stdout);
    #endif
    ios::sync_with_stdio(false); cin.tie(0); 
    int T=1;
    // scanf("%d",&T);
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
