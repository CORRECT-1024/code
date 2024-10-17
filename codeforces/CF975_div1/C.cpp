#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void dfs(int x, int len, vector<vector<int> >&bian, vector<int>&d) {
    d[x] = len;
    for (int i=0; i<bian[x].size(); i++) {
        if(d[bian[x][i]] || bian[x][i] == 1)  continue;
        dfs(bian[x][i], len + 1, bian, d);
    }
}
void work() {
    int n;
    cin >> n;
    vector<vector<int> > bian(n+10, vector<int>());
    vector<int> du(n+10, 0);
    for (int i=1; i<n; i++) {
        int u, v;  cin >> u >> v;
        bian[u].push_back(v);
        bian[v].push_back(u);
        du[u] ++;
        du[v] ++;
    }
    int ans = n - 1, del = 0;
    vector<int> bo(n+10, 0), d(n+10, 0), sum(n+10, 0);
    bo[1] = 1;  d[1] = 0;
    dfs(1, 0, bian, d);
    vector<vector<int> > c(n+10, vector<int>());
    for (int i=1; i<=n; i++) {
        c[d[i]].push_back(i);
        sum[d[i]] ++;
    }
    for (int i=1; i<=n; i++) {
        sum[i] += sum[i-1];
    }
    for (int i=1; i<=n; i++) {
        queue<int> delqu;
        if (c[i].size() == 0) break;
        for (int j=0; j<c[i].size(); j++) {
            bo[c[i][j]] = 1;
            if (du[c[i][j]] == 1) {
                delqu.push(c[i][j]);
            }
        }
        int fans = sum[n] - sum[i] + del;
        ans = min(ans, fans);
        while (!delqu.empty()) {
            int t = delqu.front();
            delqu.pop();
            del ++;
            for (auto&x : bian[t]) {
                if (bo[x] == 0 || x == 1) continue;
                du[x] --;
                if (du[x] == 1) {
                    delqu.push(x);
                    bo[x] = 0;
                }
            }
        }
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
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
