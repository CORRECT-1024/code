//sad 读了个假题
//如果是把某些数都增加相同的数，这题该怎么做？
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL n, k;
    cin >> n >> k;
    vector<LL> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    sort(&a[1], &a[n+1], [&](LL &x, LL &y) {
        return x > y;
    });
    LL ans = 0, d = 0;
    for (int i=1; i<=n; i++) {
        if (i & 1) {
            ans += a[i];
        } else {
            ans -= a[i];
            d += a[i-1] - a[i];
        }
    }
    ans -= min(k, d);
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
    // scanf("%d",&T);
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
