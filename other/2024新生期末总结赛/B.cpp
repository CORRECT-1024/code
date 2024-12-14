#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL a1, b1, c1, a2, b2, c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    LL d1 = 2 * (a1 + b1) * c1 + a1 * b1;
    LL d2 = 2 * (a2 + b2) * c2 + a2 * b2;
    if (d1 >= d2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
