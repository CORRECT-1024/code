// tmd自作聪明，我tm在写什么啊
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL x, m;
    cin >> x >> m;
    LL ans = 0;
    LL p = 1, pd = 0;
    while (p <= x) {
        p <<= 1;
        pd ++;
    }
    for (int i=1; i<p; i++) {
        LL y = x ^ i;
        if (y && y <= m && (x % i == 0 || y % i == 0)) {
            ans ++;
            // cout << y << '\n';
        }
    }
    // if (m >= p) {
    //     LL num = m / p, yu = m % p;
    //     for (int i=0; i<p; i++) {
    //         LL y = x ^ i;
    //         LL fnum = num;
    //         if (y > yu)  fnum --;
    //         LL fi = max(i, 1);
    //         while (fi % 2 == 0)  fi >>= 1;
    //         ans += fnum / fi;
    //         // cout << y << ' ' << fnum / fi << '\n';
    //     }
    // }
    cout << ans << '\n';
    // cout << '\n';
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
