#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL n, m;
    cin >> n >> m;
    if (m == 1) {
        cout << 1 << '\n';
        return;
    }
    LL num = m, p = 1;
    LL ans = 1, ansnum = m;
    while (true) {
        num *= m;
        p ++;
        if (abs(num - n) < abs(ansnum - n)) {
            ansnum = num;  ans = p;
        }
        if (num >= n)  break;
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
    while(T--) {
        work();
    }

   return 0;
}
