#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL n, b, c;
    cin >> n >> b >> c;
    if (b == 0) {
        if (c < n - 2) {
            cout << "-1\n"; return;
        }
        if (c > n - 1) {
            cout << n << '\n';
        } else {
            cout << n - 1 << '\n';
        }
        return;
    }
    LL l = 1, r = n / b + 1;
    while (l < r) {
        LL mid = ((l + r + 1) >> 1);
        if (b * (mid - 1) + c <= n - 1) l = mid;
        else r = mid - 1;
    }
    if (b * (l - 1) + c > n - 1) l --;
    cout << n - l << '\n';
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
