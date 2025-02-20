#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int mod = 998244353;
const int N = 2e5 + 10;
LL jc[N];

LL power(LL a, LL n) {
    LL ans = 1;
    while (n) {
        if (n & 1) ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}
LL c(LL n, LL m) {
    LL ans = jc[m] * power(jc[m-n], mod - 2) % mod;
    ans = ans * power(jc[n], mod - 2) % mod;
    return ans;
    // LL p = 1;
    // for (int i=0; i<n; i++) {
    //     p = p * (m - i) % mod;
    // }
    // LL q = 1;
    // for (int i=1; i<=n; i++) {
    //     q = q * i % mod;
    // }
    // p = p * power(q, mod - 2) % mod;
    // return p;
}
void init() {
    jc[0] = 1;
    for (int i=1; i<N-5; i++) {
        jc[i] = jc[i-1] * i % mod;
    }
}
void work() {
    int n;
    cin >> n;
    vector<int> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    vector<int> num(n+10, 0);
    for (int i=1; i<=n; i++) {
        num[a[i]] ++;
    }
    vector<LL> f(n+10, 0);
    LL f0 = power(2, n);
    for (int i=1; i<=n; i++) {
        f[i] = f0;
    }
    int lanum = n;
    LL ans = 0;
    for (int i=0; i<n; i++) {
        if (num[i] == 0) break;
        LL sum = power(2, num[i]), p = sum;
        for (int j=1; j<=min(num[i], lanum); j++) {
            LL fp = f[j];
            sum = (sum + mod - c(j-1, num[i])) % mod;
            fp = fp * power(p, mod - 2) % mod;
            fp = fp * sum % mod;
            ans = (ans + fp) % mod;
            // cout << sum << ' ' << ans << '\n';
            f[j] = fp;
        }
        lanum = min(lanum, num[i]);
    }
    cout << ans << '\n';
}
int main()
{
    #ifdef QHK
    freopen("qi.in","r",stdin);
    freopen("qi.out","w",stdout);
    #endif
    ios::sync_with_stdio(false); cin.tie(0); 
    init();
    int T=1;
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
