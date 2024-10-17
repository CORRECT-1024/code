#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL n, x;
    cin >> n >> x;
    vector<LL> a(n+10, 0);
    map<LL, LL> mp;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        mp[a[i] % x] = 1e9;
    }
    sort(&a[1], &a[n+1], [&](LL &fx, LL &fy) {
        if ((fx%x) == (fy % x) ) {
            return fx < fy;
        }
        return (fx%x) < (fy % x);
    });
    LL ans = n, la = -1, lanum = -1;
    for (int i=1; i<=n; i++) {
        LL b = a[i] % x, to = -1;
        if (b == la) {
            to = lanum + x;
        } else {
            if (i != 1) {
                mp[la] = min(mp[la], lanum + x);
            }
            la = b;
            to = b;
        }
        if (a[i] > to) {
            mp[b] = min(mp[b], to);
        }
        lanum = to;
    }
    mp[la] = min(mp[la], lanum + x);
    for (int i=0; i<x; i++) {
        if (mp.find(i) == mp.end()) {
            ans = min(ans, (LL)i);  break;
        } else {
            ans = min(ans, mp[i]);
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
    // scanf("%d",&T);
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
