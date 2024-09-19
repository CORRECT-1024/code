//感觉今晚脑子确实不太好用，这题竟然一开始想了个麻烦做法，差点把自己绕进去
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL n, x1, x2;
    cin >> n >> x1 >> x2;
    LL x = __gcd(x1, x2);
    vector<LL> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        a[i] %= x;
    }
    sort(&a[1], &a[n+1]);
    LL maxa = a[n];
    LL ans = x;
    for (int i=1; i<=n; i++) {
        if (a[i] + x <= maxa)  continue;
        ans = min(ans, maxa - a[i]);
        maxa = a[i] + x;
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
