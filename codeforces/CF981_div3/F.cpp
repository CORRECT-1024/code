#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int mod = 1e9 + 7;

void work() {
    LL n, k;
    cin >> n >> k;
    n %= mod;
    if (k == 1) {
        cout << n << '\n';
        return;
    }
    LL ans = -1;
    LL p1 = 1, p2 = 1;
    for (int i=3; ;i++) {
        LL p = p1 + p2;
        p %= k;
        if (p == 0) {
            ans = i;  break;
        }
        p2 = p1;  p1 = p;
    }
    ans %= mod;
    ans *= n;
    ans %= mod;
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
