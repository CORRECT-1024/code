#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int mod = 998244353;

LL power(LL a, LL n) {
    LL ans = 1;
    while (n) {
        if (n & 1)  ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}
void work() {
    int n;
    cin >> n;
    vector<vector<int> > bian(n+10, vector<int>());
    vector<int> du(n+10, 0);
    for (int i=1; i<n; i++) {
        int u, v;  cin >> u >> v;
        du[u] ++;  du[v] ++;
        bian[u].push_back(v);
        bian[v].push_back(u);
    }
    vector<vector<int> > lian;
    vector<vector<int> > tou(n+10, vector<int>());
    queue<int> qu;
    for (int i=2; i<=n; i++) {
        if (bian[i].size() == 1) {
            qu.push(i);
            lian.push_back(vector<int>());
            tou[i].push_back(lian.size() - 1);
        }
    }
    while (!qu.empty() ) {
        int x = qu.front();  qu.pop();
        int fa = -1;
        for (auto &to : bian[x]) {
            if (to == 1 || du[to] > 1)  fa = to;
        }
        du[fa] --;
        if (fa != 1 && du[fa] == 1) {
            qu.push(fa);
        }
        int mi = 1e9, miid = -1;
        for (auto &id : tou[x]) {
            if (lian[id].size() < mi) {
                mi = lian[id].size();  miid = id;
            }
        }
        lian[miid].push_back(x);
        tou[fa].push_back(miid);
    }
    vector<LL> ans(n+10, -1);
    ans[1] = 1;
    qu.push(1);
    while (!qu.empty() ) {
        int x = qu.front();  qu.pop();
        for (auto &id : tou[x]) {
            if (ans[lian[id][0]] != -1)  continue;
            int len = lian[id].size();
            for (int i=0; i<len; i++) {
                ans[lian[id][i]] = ans[x] * i % mod * power(len, mod - 2) % mod;
                qu.push(lian[id][i]);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i] << ' ';
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
