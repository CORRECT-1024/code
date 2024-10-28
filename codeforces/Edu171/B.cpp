#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    int ma1 = -1, ma2 = -2;
    vector<LL> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    LL ans = 0;
    for (int i=2; i<=n; i+=2) {
        ans = max(ans, a[i] - a[i-1]);
    }
    for (int i=1; i<=n; i++) {
        if (((i - 1) & 1) || (n - i) & 1) continue;
        LL fans = -1;
        for (int j=2; j<i; j+=2) {
            fans = max(fans, a[j] - a[j-1]);
        }
        for (int j=i+2; j<=n; j+=2) {
            fans = max(fans, a[j] - a[j-1]);
        }
        ans = min(ans, fans);
        // cout << fans << '\n';
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
