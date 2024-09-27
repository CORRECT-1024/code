#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL n, m;
    cin >> n >> m;
    vector<LL> a(n+10, 0);
    LL mx = 0, sum = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        sum += a[i];
    }
    LL ans = (sum + m) / mx;
    ans = min(ans, n);
    if (ans >= n) {
        ans = n;
    }
    mx = (sum + m) / ans;
    while (ans * mx < sum) {
        mx += (sum - ans * mx - 1) / ans + 1;
        ans = (sum + m) / mx;
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
