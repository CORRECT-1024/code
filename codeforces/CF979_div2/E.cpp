#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int mod = 998244353;

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
    LL p = 1;
    for (int i=0; i<n; i++) {
        p = p * (m - i) % mod;
    }
    LL q = 1;
    for (int i=1; i<=n; i++) {
        q = q * i % mod;
    }
    p = p * power(q, mod - 2) % mod;
    return p;
}
void work() {
    int n;
    cin >> n;
    vector<int> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    vector<vector<LL> > f(n+10, vector<LL> ());
    vector<int> num(n+10, 0);
    for (int i=1; i<=n; i++) {
        num[a[i]+1] ++;
    }
    LL f0 = power(2, n);
    for (int i=1; i<=n; i++) {
        f[0].push_back(f0);
    }
    int lanum = n;
    LL ans = 0;
    for (int i=1; i<=n; i++) {
        LL sum = power(2, num[i]), p = sum;
        for (int j=0; j<min(num[i], lanum); j++) {
            LL fp = f[i-1][j];
            sum = (sum + mod - c(j, num[i])) % mod;
            fp = (fp * fp) % mod * power(sum, mod - 2) % mod;
            ans = (ans + fp) % mod;
            f[i].push_back(fp);
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
    int T=1;
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
