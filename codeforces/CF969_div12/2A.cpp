#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int l, r;
    cin >> l >> r;
    if (r < l + 2) {
        cout << 0 << '\n';
        return;
    }
    if (l % 2 == 0) l ++;
    int ans = (r - l + 1) / 4;
    if ((r - l + 1) % 4 == 3) ans ++;
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
