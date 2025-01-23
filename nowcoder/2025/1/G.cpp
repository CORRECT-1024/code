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
    LL ans = 0, sum = 0;
    for (int i=1; i<=n; i++) {
        ans += abs(a[i] - i);
        sum += a[i] - i;
    }
    if (sum == 0) {
        cout << ans / 2 << '\n';
    } else {
        cout << "-1\n";
    }
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
