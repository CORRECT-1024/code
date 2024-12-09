#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m+10, 0);
    for (int i=1; i<=m; i++) {
        cin >> a[i];
    }
    sort(&a[1], &a[m+1], [&](int &x, int &y) {
        return x > y;
    });
    vector<int> ans(n+10, 0);
    for (int i=1; i<=n; i++) {
        int d = 0;
        for (int j=1; j*j <= i; j++) {
            if (i % j)  continue;
            int fj = i / j;
            d = max({d, ans[fj], ans[j]});
        }
        d ++;
        ans[i] = d;
        if (d > m) {
            cout << -1 << '\n';
            return;
        }
    }
    for (int i=1; i<=n; i++) {
        cout << a[ans[i]] << ' ';
    }
    cout << '\n';
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
