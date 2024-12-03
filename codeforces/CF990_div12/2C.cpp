#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<array<int, 2> > a(n+10);
    int num1 = 0, num2 = 0, d = -1e9, p = -1e9;
    LL ans = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i][0];
    }
    for (int i=1; i<=n; i++) {
        cin >> a[i][1];
    }
    for (int i=1; i<=n; i++) {
        ans += max(a[i][0], a[i][1]);
        if (a[i][0] >= a[i][1]) {
            num1 ++;
            p = max(p, a[i][1]);
            // if (num2 == 0) {
            //     d = max(d, a[i][1] - a[i][0]);
            // }
        } else {
            num2 ++;
            p = max(p, a[i][0]);
            // if (num1 == 0) {
            //     d = max(d, a[i][0] - a[i][1]);
            // }
        }
    }
    // if (num1 == 0 || num2 == 0)  ans += d;
    ans += p;
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
    while(T--) {
        work();
    }

   return 0;
}
