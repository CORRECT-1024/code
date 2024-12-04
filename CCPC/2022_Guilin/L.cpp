#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int k = i > m * 2 ? 1 : m - ((i - 1) / 2);
        for (int j=1; j<=m; j++) {
            if (j == k) {
                cout << 1 << ' ';
            } else {
                cout << 0 << ' ';
            }
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
