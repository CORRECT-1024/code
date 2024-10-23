#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL a, b;
    cin >> a >> b;
    LL l = 0, r = a;
    if (b > 2 * (a - 1) + 1) {
        cout << 0 << '\n';
        return;
    }
    while (l < r) {
        LL mid = ((l + r ) >> 1);
        if (2 * mid + a - mid >= b) r = mid;
        else l = mid + 1;
    }
    cout << a - l << '\n';
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
