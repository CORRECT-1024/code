#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<int> a(n+10, 0);
    vector<array<int, 2> > b;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        b.push_back({a[i], i});
    }
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    sort(b.begin(), b.end());
    int minum = b[0][0], manum = b[n-1][0];
    int l = b[0][1], r = b[0][1];
    if (n == 2) {
        cout << min({2 * (b[1][0] - b[0][0]), 2 * b[1][0] - b[0][0], abs(b[1][0] - 2 * b[0][0])}) << '\n';
        return;
    }
    int ans = max(minum * 2, manum) - min(minum * 2, b[1][0]);
    int fma = minum;
    int al = l, ar = r;
    for (int i=1; i<n-1; i++) {
        auto &[x, xid] = b[i];
        if (x >= minum * 2) break;
        l = min(l, xid);  r = max(r, xid);
        while (al > l) {
            al --;  fma = max(fma, a[al]);
        }
        while (ar < r) {
            ar ++;  fma = max(fma, a[ar]);
        }
        ans = min(ans, max(fma * 2, manum) - min(minum * 2, b[i+1][0]));
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
