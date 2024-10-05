#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    string a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 0 << '\n';
        return;
    }
    int ans = 1;
    for (int i=0; i<min(a.size(), b.size()); i++) {
        if (a[i] != b[i]) {
            cout << ans << '\n';
            return;
        }
        ans ++;
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
    // cin >> T;
    while(T--){
        work();
    }

   return 0;
}
