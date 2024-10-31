#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int x;  cin >> x;
            if (x < 0) {
                 x = x * -1;
                 mp[j - i] = max(mp[j - i], x);
            }
        }
    }
    LL ans = 0;
    for (auto &[_, x] : mp) ans += x;
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
