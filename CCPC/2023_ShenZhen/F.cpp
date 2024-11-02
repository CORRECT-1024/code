#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

bool dfs(int fa, int id, stack<int> &st, vector<int> &vis, int &be, vector<vector<int> > &bian) {
    if (vis[id] ) {
        be = id;  return true;
    }
    st.push(id);  vis[id] = 1;
    for (auto &to : bian[id]) {
        if (to == fa)  continue;
        if (dfs(id, to, st, vis, be, bian) )  return true;
    }
    st.pop();
    return false;
}
void work() {
    int n;
    cin >> n;
    vector<vector<int> > bian(n + 10, vector<int> ());
    vector<int> du(n+10, 0), num(10, 0);
    for (int i=1; i<=n; i++) {
        int u, v;  cin >> u >> v;
        du[u] ++;  du[v] ++;
        bian[u].push_back(v);
        bian[v].push_back(u);
    }
    for (int i=1; i<=n; i++) {
        num[du[i]] ++;
    }
    stack<int> st;
    vector<int> vis(n+10, 0);
    int be = -1;
    dfs(0, 1, st, vis, be, bian);
    for (int i=1; i<=n; i++)  vis[i] = 0;
    vector<int> huan;
    while (st.top() != be) {
        huan.push_back(st.top());
        vis[st.top()] = 1;
        st.pop();
    }
    huan.push_back(be);
    vis[be] = 1;
    LL ans = 0;
    for (int i=0; i<huan.size(); i++) {
        int u = huan[i], v = huan[(i + 1) % huan.size()];
        // cout << u << ' ' << v << '\n';
        num[du[u]] --;  num[du[v]] --;  num[du[u] - 1] ++;  num[du[v] - 1] ++;
        if (num[5] == 0)  ans += num[1] + num[2] + num[3];
        num[du[u]] ++;  num[du[v]] ++;  num[du[u] - 1] --;  num[du[v] - 1] --;
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
    // cin >> T;
    while(T--){
        work();
    }

   return 0;
}
