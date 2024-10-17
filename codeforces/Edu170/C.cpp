#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    sort(&a[1], &a[n+1]);
    int r = 1, ans = 0;
    for (int i=1; i<=n; i++) {
        r = max(r, i);
        while (r < n && a[r + 1] <= a[i] + k - 1 && a[r+1] <= a[r] + 1) {
            r ++;
        }
        ans = max(ans, r - i + 1);
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
