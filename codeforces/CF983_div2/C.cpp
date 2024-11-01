#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<LL> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    sort(&a[1], &a[n+1]);
    int ans = n-1;
    int r = 1;
    for (int i=1; i<n; i++) {
        r = max(r, i);
        while (r < n && a[r + 1] < a[i] + a[i + 1]) {
            r ++;
        }
        // cout << i << ' ' << r << ' ' << i - 1 + n - r << '\n';
        ans = min(ans, i - 1 + n - r);
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
