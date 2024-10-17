#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL n;
    cin >> n;
    vector<int> a(n+10, 0);
    LL sum = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (n <= 2) {
        cout << -1 << '\n';
        return;
    }
    sort(&a[1],&a[n + 1]);
    LL ans = max((LL)0, a[n / 2 + 1] * n * 2 + 1 - sum);
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
