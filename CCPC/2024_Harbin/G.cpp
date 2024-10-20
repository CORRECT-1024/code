#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define endl '\n'

void dfs(int x, vector<int>&bo, vector<vector<int> > &bian) {
    bo[x] = 1;
    for (auto&to : bian[x]) {
        if (bo[to] )  continue;
        dfs(to, bo, bian);
    }
}
void work() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int> > bian(n+10, vector<int> ());
    vector<int> bo(n+10, 0), ak(k+10, 0);
    for (int i=1; i<=k; i++) {
        cin >> ak[i];
        bo[ak[i]] = 1;
    }
    int id = 1;
    for (int i=1; i<=n; i++) {
        if (bo[i])  continue;
        id = i;  break;
    }
    for (int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        bian[u].push_back(v);
        bian[v].push_back(u);
    }
    for (int i=1; i<=k; i++) {
        bian[ak[i]] = vector<int>();
    }
    bo = vector<int> (n+10, 0);
    dfs(id, bo, bian);
    bool boo = true;
    for (int i=1; i<=n; i++) {
        if (!bo[i] ) {
            boo = false;
            break;
        }
    }
    if (!boo ) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    queue<int> qu;
    qu.push(id);
    bo = vector<int> (n+10, 0);
    bo[id] = 1;
    vector<pair<int, vector<int> > > ans;
    while (!qu.empty()) {
        int x = qu.front();  qu.pop();
        vector<int> aa;
        for (auto & to : bian[x]) {
            if (bo[to] ) continue;
            aa.push_back(to);
            qu.push(to);  
            bo[to] = 1;
        }
        if (aa.size() > 0) {
            ans.push_back({x, aa});
        }
    }
    cout << ans.size() << '\n';
    for (int i=0; i<ans.size(); i++) {
        cout << ans[i].first << ' ' ;
        cout << ans[i].second.size() << ' ';
        for (auto&to : ans[i].second) {
            cout << to << ' ';
        }
        cout << endl;
    }
}
int main()
{
    freopen("qi.in","r",stdin);
    freopen("qi.out","w",stdout);
    ios::sync_with_stdio(false);  cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        work();
    }

    return 0;
}