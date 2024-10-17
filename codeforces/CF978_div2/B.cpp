#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, k;
    cin >> n >> k;
    vector<LL> a(n+10, 0);
    LL l = 1, r = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        l = max(l, a[i]);
        r += a[i];
    }
    LL sum = r;
    cout << max((sum - 1) / k + 1, l) << '\n';
    return;
    while (l < r) {
        LL mid = ((l + r - 1) >> 1);
        if (mid * k >= sum) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
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
