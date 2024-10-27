#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    if (n < 2 || n == 3) {
        cout << -1 << '\n';
        return;
    }
    string ans = "";
    if (n == 2) {
        ans = "66";
        cout << ans << '\n';
        return;
    }
    n -= 2;
    if (n & 1) {
        n -= 3;
        for (int i=1; i<=n; i++) ans += '3';
        ans += "363";
    } else {
        for (int i=1; i<=n; i++) ans += '3';
    }
    ans += "66";
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
    while(T--){
        work();
    }

   return 0;
}
