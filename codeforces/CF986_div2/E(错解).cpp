// 想错力(悲) 
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int mod = 998244353;

array<LL, 2> funmin(array<LL, 2> x, array<LL, 2> y) {
    if (x[0] * y[1] < y[0] * x[1])  return x;
    return y;
}
void dfs(int x, LL ceng, array<LL, 2> mi, vector<vector<int> > &bian, vector<array<LL, 2> > &ans, vector<int> &len) {
    mi = funmin(mi, {len[x], ceng + len[x]});
    ans[x] = mi;
    cout << x << ": " << len[x] << ' ' << ceng + len[x] << ' ' << ans[x][0] << ' ' << ans[x][1] << '\n';
    for (auto &to : bian[x]) {
        if (to == 1 || ans[to][1] != 1)  continue;
        dfs(to, ceng + 1, mi, bian, ans, len);
    }
}

LL power(LL a, LL n) {
    LL ans = 1;
    while (n ) {
        if (n & 1) ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}
void work() {
    int n;
    cin >> n;
    vector<vector<int> > bian(n+10, vector<int>());
    for (int i=1; i<n; i++) {
        int u, v;  cin >> u >> v;
        bian[u].push_back(v);
        bian[v].push_back(u);
    }
    vector<int> len(n+10, 1e9);
    queue<int> qu;
    for (int i=2; i<=n; i++) {
        if (bian[i].size() == 1) {
            qu.push(i);   len[i] = 0;
        }
    }
    while (!qu.empty() ) {
        int x = qu.front();  qu.pop();
        for (auto &to : bian[x]) {
            if (len[to] <= len[x] + 1) continue;
            if (len[to] == 1e9) qu.push(to);
            len[to] = len[x] + 1;
        }
    }
    vector<array<LL, 2> > ans(n+10, {1, 1});
    dfs(1, 0, {(LL)1, (LL)1}, bian, ans, len);
    for (int i=1; i<=n; i++) {
        cout << (ans[i][0] * power(ans[i][1], mod - 2)) % mod << ' ';
        // cout << ans[i][0] << ' ' << ans[i][1] << '\n';
    }
    cout << '\n';
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
