#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod = 998244353;

LL power(LL a, LL n) {
    a %= mod;  
    // n %= mod;
    LL ans = 1;
    while (n) {
        if (n & 1)  ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}
void work() {
    LL x, y;
    cin >> x >> y;
    LL a, b, c;
    cin >> a >> b >> c;
    c = a + b;
    LL ans = 0;
    LL p = 1;
    LL pa = a * power(c, mod - 2) % mod;
    // LL pb = b * power(c, mod - 2) % mod;
    // cout << pa + pb << '\n';
    while (true) {
        if (x == y) {
            ans = (ans + p * pa % mod) % mod;
            break;
        }
        if (x > y) {
            LL d = (x - 1) / y;
            LL fp = power(1 + mod - pa, d) % mod;
            ans = (ans + p * (1 + mod - fp) % mod) % mod;
            x -= y * d;
            p = p * fp % mod;
        } else {
            LL d = (y - 1) / x;
            LL fp = power(pa, d) % mod;
            y -= x * d;
            p = p * fp % mod;
        }
    }
    cout << ans << '\n';
}
int main()
{
    #ifdef QHK
    freopen("qi.in","r",stdin);
    freopen("qi.out","w",stdout);
    #endif
    ios::sync_with_stdio(false);  cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        work();
    }
    // cout << (1 * power(998244352, mod - 2)) % mod <<  '\n';
    // cout << power(998244352, 1e9) % mod;

    return 0;
}