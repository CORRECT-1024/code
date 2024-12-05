#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

int ans = 0;

int dfs(int x, vector<vector<int> > &bian, vector<int> &bo) {
    bo[x] = 1;
    int num = 0, ma1 = -1, ma2 = -1;
    for (auto &to : bian[x]) {
        if (bo[to] )  continue;
        num ++;
        int p = dfs(to, bian, bo);
        if (p >= ma1) {
            ma2 = ma1;  ma1 = p;
        } else if (p > ma2) {
            ma2 = p;
        }
    }
    // cout << x << ' ' << num << ' ' << ma1 << ' ' << ma2 << '\n';
    if (num == 0) {
        return 1;
    }
    ans = max(ans, ma1 + ma2 + num - 2);
    if (x != 1) {
        ans = max(ans, ma1 + 1);
        ans = max(ans, ma1 + ma2 + num - 2 + 1);
    }
    return ma1 + num - 1;
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
    ans = 0;
    vector<int> bo(n+10, 0);
    ans = max(ans, dfs(1, bian, bo) );
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
