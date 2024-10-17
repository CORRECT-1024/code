#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<int> a(n+10, 0);
    for (int i=1; i<=n; i++)  cin >> a[i];
    LL ans = 0, last = -1;
    int cnt = n;
    while (cnt) {
        int mi = 1e9;
        for (int i=1; i<=n; i++) {
            // cin >> a[i];
            mi = min(mi, a[i]);
        }
        ans += mi;
        cnt --;
        if (mi == last)  break;
        last = mi;
        for (int i=1; i<=n; i++) {
            a[i] = gcd(a[i], mi);
        }
    }
    ans += cnt * last;
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
