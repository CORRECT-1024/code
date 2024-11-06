#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL n, k;
    cin >> n >> k;
    vector<LL> a(n+10);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    LL m;  cin >> m;
    LL ans = 0;
    priority_queue<LL, vector<LL>, greater<> > pri;
    for (int i=1; i<=n; i++) {
        LL d = k - (a[i] % k);
        pri.push(d);
        ans += a[i] / k;
    }
    while (!pri.empty() && m >= pri.top()) {
        m -= pri.top();  pri.pop();
        ans ++;
    }
    ans += m / k;
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
