#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL n, x, y;
    cin >> n >> x >> y;
    if (n == 0) {
        cout << 0 << '\n';
        return;
    }
    LL ans = 1e15;
    if (x <= y) {
        ans = (n - 1) / x + 1;
    } else {
        ans = (n - 1) / y + 1;
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
    // scanf("%d",&T);
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
