#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int l1, l2, r1, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if (l1 > r2 || l2 > r1) {
        cout << 1 << '\n';
        return;
    }
    int al, ar;
    al = max(max(l1, l2) - 1, min(l1, l2));
    ar = min(min(r1, r2) + 1, max(r1, r2));
    // cout << al << ' ' << ar << ' ';
    cout << ar - al << '\n';
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
