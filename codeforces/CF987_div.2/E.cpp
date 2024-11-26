// sb 改代码20秒，in queue10分钟
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

// LL power(LL a, LL n) {
//     LL ans = 1;
//     while (n ) {
//         if (n & 1) ans = ans * a;
//         a = a * a;
//         n >>= 1;
//     }
//     return ans;
// }
int dfs(int x, vector<vector<int> > &bian) {
    map<int, int> mp;
    int ans = 0, p = 0;
    for (auto &to : bian[x]) {
        int d = dfs(to, bian);
        ans = max(ans, d);
        mp[d] ++;
    }
    int laval = 0, lanum = 0;
    for (auto &[val, num] : mp) {
        while (lanum && laval < val && lanum > 1) {
            laval ++;  lanum = (lanum + 1) / 2;
        }
        // if (lanum ) {
        //     LL d = 1e9;
        //     if (val - laval <= 20) {
        //         LL p = power(2, val - laval);
        //         lanum = (lanum + p - 1) / p;
        //     }
        // }
        laval = val;  lanum = num + lanum;
    }
    while (lanum > 1) {
        laval ++;  lanum = (lanum + 1) / 2;
    }
    if (ans == laval) laval ++;
    ans = laval;
    return ans;
}
void work() {
    int n;
    cin >> n;
    vector<vector<int> > bian(n+10, vector<int>());
    for (int i=2; i<=n; i++) {
        int fa;  cin >> fa;
        bian[fa].push_back(i);
    }
    int ans = dfs(1, bian) - 1;
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
