#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, k;
    cin >> n >> k;
    vector<LL> a(n + k + 10, 0);
    for (int i=1; i<=k; i++) {
        int b, c;   cin >> b >> c;
        a[b] += c;
    }
    sort(&a[1], &a[k+1], [&](LL x, LL y) {
        return x > y;
    });
    int ans = 0;
    for (int i=1; i<=n; i++) {
        ans += a[i];
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
