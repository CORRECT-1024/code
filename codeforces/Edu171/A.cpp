#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL x, y, k;
    cin >> x >> y >> k;
    x = min(x, y);
    cout << 0 << ' ' << 0 << ' ' << x << ' ' << x << '\n';
    cout << 0 << ' ' << x << ' ' << x << ' ' << 0 << '\n';
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
