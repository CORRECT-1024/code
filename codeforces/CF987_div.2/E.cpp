// sb 改代码20秒，in queue10分钟
// 得注意细节，这题要是赛时，可能就被hack了
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

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
        // TLE
        // while (lanum && laval < val) {
        //     laval ++;  lanum = (lanum + 1) / 2;
        // }
        while (lanum && laval < val && lanum > 1) {
            laval ++;  lanum = (lanum + 1) / 2;
        }
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
