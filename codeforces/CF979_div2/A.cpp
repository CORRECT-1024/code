#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    int mi = 1e9, ma = -1;
    for (int i=1; i<=n; i++) {
        int x;   cin >> x;
        mi = min(mi, x);
        ma = max(ma, x);
    }
    LL ans = (LL)(n - 1) * (ma - mi);
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
