#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void work() {
    LL n;
    cin >> n;
    LL ans = 1500;
    for (int i=1; i<=n; i++) {
        LL x;  cin >> x;
        ans += x;
        if (ans >= 4000) {
            cout << i << '\n';  
            return;
        }
    }
    cout << -1 << '\n';
}
int main()
{
    #ifdef QHK
    freopen("qi.in","r",stdin);
    freopen("qi.out","w",stdout);
    #endif
    ios::sync_with_stdio(false);  cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        work();
    }

    return 0;
}