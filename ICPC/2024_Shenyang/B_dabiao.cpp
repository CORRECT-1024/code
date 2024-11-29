#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n = 5, m = 7;
    vector<vector<int> > a(n+10, vector<int>(m+10, 0));
    for (int i=1; i<=n; i++) a[i][0] = (i - 1) * m + 1;
    for (int i=1; i<=m; i++) a[0][i] = (i - 1) * n + 1;
    map<int, int> mp;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            a[i][j] = a[i][0] * a[0][j] % (n * m);
            cout << a[i][j] << ' ';
            if (mp[a[i][j]] ) {
                cout << "error\n";
                return;
            }
            mp[a[i][j]] = 1;
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
