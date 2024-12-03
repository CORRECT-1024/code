#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    LL sum = 0, ans = 0;
    for (int i=1; i<=n; i++) {
        LL x;  cin >> x;
        x += sum;
        // cout << x << '\n';
        if ((int)sqrt(x) * (int)sqrt(x) == x && (int)(sqrt(x)) & 1) ans ++;
        sum = x;
    }
    cout << ans << '\n';
    // cout << '\n';
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
