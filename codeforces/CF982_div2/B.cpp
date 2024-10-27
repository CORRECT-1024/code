#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<int> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    int la = -1;
    vector<int> b(a);
    sort(&b[1], &b[n+1], [&](int x, int y) {
        return x < y;
    });
    int ans = n, id = 0;
    a[0] = 0;
    for (int i=0; i<n; i++) {
        if (a[i+1] <= la)  continue;
        while (id < n && b[id + 1] <= a[i+1]) id ++;
        // cout << id << '\n';
        ans = min(ans, i + n - id);
        la = a[i+1];
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
