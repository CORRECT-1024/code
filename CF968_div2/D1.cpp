#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL n, m;
    cin >> n >> m;
    LL ma = 0;
    for (int i=1; i<=n; i++) {
        int l;  cin >> l;
        vector<LL> a(l+10, 0);
        for (int i=1; i<=l; i++) {
            cin >> a[i];
        }
        sort(&a[1], &a[l+1]);
        LL u = -1, v = -1;
        int k = 0;
        for (int i=1; i<=l; i++) {
            if (a[i] < k)  continue;
            if (a[i] == k) {
                k ++;  continue;
            }
            while (a[i] > k) {
                if (u == -1)  u = k;
                else {
                    v = k;  break;
                }
                k ++;
            }
            if (a[i] == k) {
                k ++;  continue;
            }
        }
        if (u == -1) {
            u = k;  v = k + 1;
        } else if (v == -1) {
            v = k;
        }
        // cout << u << ' ' << v << '\n';
        ma = max(ma, v);
    }
    LL ans;
    ans = (min(m, ma) + 1) * ma;
    if (m > ma) {
        ans += (m + ma + 1) * (m - ma) / 2;
    }
    cout << ans << '\n';
    // cout << ma << '\n';
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
