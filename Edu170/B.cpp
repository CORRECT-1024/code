#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;

void work() {
    int n;
    cin >> n;
    vector<LL> a(n+10, 0), b(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> b[i];
    }
    vector<LL> ans(N+10, 0);
    ans[0] = 1;
    for (int i=1; i<=N; i++) {
        ans[i] = ans[i-1] * 2 % mod;
    }
    for (int i=1; i<=n; i++) {
        if (b[i] == a[i]) b[i] = 1;
        else b[i] = ans[b[i]];
        cout << b[i] << '\n';
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
    while(T--){
        work();
    }

   return 0;
}
