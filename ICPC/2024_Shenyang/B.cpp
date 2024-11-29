#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL n, m;
    cin >> n >> m;
    LL mod = n * m;
    if (__gcd(n, m) == 1) {
        cout << "Yes\n";
        for (int i=1; i<=n; i++) {
            cout << ((i - 1) * m + 1) % mod << ' ';
        }
        cout << '\n';
        for (int i=1; i<=m; i++) {
            cout << ((i - 1) * n + 1) % mod << ' ';
        }
        cout << '\n';
    } else {
        cout << "No\n";
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
    cin >> T;
    while(T--) {
        work();
    }

   return 0;
}
