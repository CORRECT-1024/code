#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, m;
    cin >> n >> m;
    if (n - m > 26 || m >= n) {
        cout << "NO" << '\n';
        return;
    }
    string ans = "";
    for (int i=0; i<n-1; i++) {
        ans += 'a' - 1 + (i % 26) + 1;
    }
    ans += ans[m-1];
    cout << "YES\n";
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
    while(T--) {
        work();
    }

   return 0;
}
