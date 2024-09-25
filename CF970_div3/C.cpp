#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL al, ar;
    cin >> al >> ar;
    LL len = ar - al + 1;
    LL l = 1, r = len;
    while (l < r) {
        LL mid = ((l + r + 1) >> 1);
        if (1 + mid * (mid - 1) / 2 <= len) l = mid;
        else r = mid - 1;
    }
    cout << l << '\n';
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
