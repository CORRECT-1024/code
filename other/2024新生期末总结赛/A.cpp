#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<int> ans(n*n+10, 0);
    int x, id = 1, p = 0;
    while (cin >> x ) {
        for (int i=1; i<=x; i++) {
            ans[id] = p;  id ++;
        }
        p ^= 1;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << ans[(i - 1) * n + j];
        }
        cout << '\n';
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
