#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<array<int, 2> > a(n+10);
    int maxx = 0, maxy = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i][0] >> a[i][1];
        maxx = max(maxx, a[i][0]);
        maxy = max(maxy, a[i][1]);
    }
    // vector<int> h(maxx + 10, 0);
    // for (int i=1; i<=n; i++) {
    //     for (int j=1; j<=a[i][0]; j++) {
    //         h[j] = max(h[j], a[i][1]);
    //     }
    // }
    int ans = (maxx + maxy) * 2;
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
