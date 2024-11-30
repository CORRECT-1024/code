#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL x, k;
    cin >> x >> k;
    LL ans = 0;
    LL la = -1;
    while (la != 1) {
        ans ++;
        if (x != 1 && x * x != la) {
            ans += k;
        }
        la = x;  x = sqrt(x);
        if (k == 0)  break;
        k --;
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
    // cin >> T;
    while(T--) {
        work();
    }

   return 0;
}
