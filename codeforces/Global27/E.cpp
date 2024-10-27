#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL x, y, z, k;
    cin >> x >> y >> z >> k;
    LL ans = x + y * z;
    for (LL i=1; (i + 1) * i / 2 * k <= z; i++) {
        LL zz = z - i * (i - 1) / 2 * k, fx = (i - 1) * k, d = 1;
        LL fans = (i - 1) * (x * k + y);
        LL num = (zz + fx + d - 1) / (fx + 1);
        LL hd = k;
        while (d <= hd && num) {
            num = (zz + fx + d - 1) / (fx + d);
            ans = min(ans, fans + num * y + x * d);
            cout << num << ' ' << d << ' ' << fans + num * y + x * d << '\n';
            // if (fans + num * y + x * d == 160) {
            //     cout << i << ' ' << zz << ' ' << fx << ' ' << num << ' ' << d << '\n';
            // }
            num --;
            if (num ) d = (zz + num - 1) / num - fx;
        }
        d = k;
        num = (zz + fx + d - 1) / (fx + d);
        ans = min(ans, fans + num * y + x * d);
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
    while(T--){
        work();
    }

   return 0;
}
