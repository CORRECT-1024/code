#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, m;
    cin >> n >> m;
    vector<LL> ans(n+10, -1);
    vector<vector<int> > to(n+10, vector<int>()), fto(n+10, vector<int>());
    vector<int> du(n+10, 0);
    vector<array<int, 2> > bian(m+10);
    for (int i=1; i<=m; i++) {
        int x, y, z;  cin >> x >> y >> z;
        du[x] += 2;
        bian[i] = {y, z};
        to[y].push_back(x);
        to[z].push_back(x);
        fto[x].push_back(i);
    }
    queue<int> qu;
    for (int i=1; i<=n; i++) {
        if (du[i] == 0) {
            qu.push(i);
        }
    }
    while (!qu.empty() ) {
        int t = qu.front();  qu.pop();
        LL num = 1;
        for (auto &id : fto[t]) {
            num = max(num, ans[bian[id][0]] + ans[bian[id][1]]);
        }
        if (num >= 1e9) {
            cout << -1 << '\n';
            return;
        }
        ans[t] = num;
        for (auto &id : to[t]) {
            du[id] --;
            if (du[id] == 0) {
                qu.push(id);
            }
        }
    }
    LL sum = 0;
    for (int i=1; i<=n; i++) {
        if (ans[i] == -1) {
            cout << -1 << '\n';
            return;
        }
        sum += ans[i];
    }
    if (sum > 1e9) {
        cout << -1 << '\n';
        return;
    }
    cout << sum << '\n';
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
