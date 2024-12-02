#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL n, k;
    cin >> n >> k;
    vector<LL> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    sort(&a[1], &a[n+1]);
    LL sum = a[n];
    for (int i=n-1; i>=1; i--) {
        if (sum + a[i] > k)  break;
        sum += a[i];
    }
    LL ans = sum >= k ? 0 : k - sum;
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
