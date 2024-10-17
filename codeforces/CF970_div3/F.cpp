#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int mod = 1e9 + 7;

LL power(LL a, LL n) {
    LL ans = 1;
    a %= mod;
    while (n) {
        if (n & 1) ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

void work() {
    LL n;
    cin >> n;
    LL sum = 0;
    vector<LL> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        sum += a[i];
        sum %= mod;
    }
    LL p = 0, q = n * (n - 1) % mod;
    for (int i=1; i<=n; i++) {
        p = (p + a[i] * (sum + mod - a[i]) % mod) % mod;
    }
    LL ans = p * power(q, mod - 2) % mod;
    cout << ans << '\n';
}
int main()
{
    #ifdef QHK
    freopen("qi.in","r",stdin);
    freopen("qi.out","w",stdout);
    #endif
    ios::sync_with_stdio(false); cin.tie(0); 
    int T=1;
    // scanf("%d",&T);
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
