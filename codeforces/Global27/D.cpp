#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int mod = 1e9 + 7;

LL power(LL a, LL n) {
    LL ans = 1;
    while (n ) {
        if (n & 1) ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}
void work() {
    int n;
    cin >> n;
    vector<LL> a(n+10, 0), b(n+10, 0), sum(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        while (a[i] % 2 == 0) {
            a[i] >>= 1;
            b[i] ++;
        }
        sum[i] = sum[i-1] + a[i];
    }
    vector<LL> ans(n+10, 0);
    ans[1] = a[1] * power(2, b[1]);
    cout << ans[1] << ' ';
    stack<array<LL, 3> > st;
    st.push({1, a[1], b[1]});
    for (int i=2; i<=n; i++) {
        LL fa = a[i] * power(2, b[i]);
        bool bo = false;
        int num = b[i];
        while (!st.empty() && (bo || fa >= st.top()[1])) {
            fa = fa * power(2, st.top()[2]);
            num += st.top()[2];
            if (fa >= mod) {
                bo = true;  fa %= mod;
            }
            st.pop();
        }
        int id = 0;
        if (!st.empty()) id = st.top()[0];
        ans[i] = ans[id] + sum[i] - sum[id];
        ans[i] %= mod;
        ans[i] = (ans[i] + fa + mod - a[i]) % mod;
        st.push({i, a[i], num});
        cout << ans[i] << ' ';
    }
    cout << '\n';
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
