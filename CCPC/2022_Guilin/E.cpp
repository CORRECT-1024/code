#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

LL power(LL a, LL n, LL mod) {
    LL ans = 1;
    if (n < 0)  return ans;
    while (n ) {
        if (n & 1) ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}
void work() {
    LL x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 > x2) {
        swap(x1, x2);  swap(y1, y2);
    }
    LL dy = abs(y1 - y2), dx = abs(x1 - x2);
    if (dy == 0) {
        cout << 0 << ' ' << y1 + 1 << '\n';
        return;
    }
    if (dx == 0) {
        cout << x1 + 1 << ' ' << 0 << '\n';
        return;
    }
    if (dx == dy) {
        cout << x1 + 1 << ' ' << y1 << '\n';
        return;
    }
    LL d = __gcd(dx, dy);
    dx /= d;  dy /= d;
    LL k = power(dy, dx - 2, dx);
    cout << k << '\n';
    LL x;
    // if (y2 > y1) x = x1 + k;
    // else x = x2 - k;
    x = x1 + k;
    LL y;
    // if (y2 > y1) 
    y = y1 + ((double)(y2 - y1) / (x2 - x1) * k + 0.5);
    // else y = y2 + (double)(y1 - y2) / (x2 - x1) * k;
    cout << x << ' ' << y << '\n';
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
