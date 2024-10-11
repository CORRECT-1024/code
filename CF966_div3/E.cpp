#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL n, m, k, w;
    cin >> n >> m >> k >> w;
    vector<LL> a(w+10, 0);
    for (int i=1; i<=w; i++) {
        cin >> a[i];
    }
    sort(&a[1],&a[w+1], [&](LL&x, LL&y) {
        return x > y;
    });
    priority_queue<LL, vector<LL>, less<>> pri;
    for (LL i=1; i<=n; i++) {
        LL d1 = min(n, i + k - 1) - max((LL)1, i - k + 1) + 1 - k + 1;
        for (LL j=1; j<=m; j++) {
            LL d2 = min(m, j + k - 1) - max((LL)1, j - k + 1) + 1 - k + 1;
            pri.push(d1 * d2);
        }
    }
    LL ans = 0;
    for (int i=1; i<=w; i++) {
        ans += pri.top() * a[i];
        pri.pop();
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
