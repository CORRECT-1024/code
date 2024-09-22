#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

int n, c;

array<LL, 2> dfs(int x, vector<vector<int> > &bian, vector<int> &bo, vector<LL> &a) {
    bo[x] = 1;
    array<LL, 2> ans = {0, 0};
    ans[0] = 0;  ans[1] = a[x];
    for (int i=0; i<bian[x].size(); i++) {
        if (bo[bian[x][i]] )  continue;
        auto p = dfs(bian[x][i], bian, bo, a);
        ans[0] += max(p[0], p[1]);
        ans[1] += max(p[0], p[1] - 2 * c);
    }
    //0：x不-c的ans， 1：x-c的ans， 2：lin【x】-c在x(bu-c)这里的ans 3: lin[x] - c && x - c -> ans[x]
    // if (x != 1 && bian[x].size() == 1) {
    //     ans[0] = 0;  ans[1] = -1 * c;
    //     ans[2] = a[x];  ans[3] = a[x] - c;
    //     return ans;
    // }
    // ans[0] = 0;  ans[1] = -1 * c;  ans[2] = a[x];  ans[3] = a[x] - c;
    // for (int i=0; i<bian[x].size(); i++) {
    //     if (bo[bian[x][i]] ) continue;
    //     auto p = dfs(bian[x][i], bian, bo, a);
    //     ans[0] += max(p[0], p[1]);
    //     ans[1] += max({p[0], p[1], p[2], p[3]});
    //     ans[3] += max(p[1], p[3]);
    //     ans[4] += max({p[0], p[1], p[3], p[4]});
    // }
    return ans;
}
void work() {
    cin >> n >> c;
    vector<LL> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    vector<vector<int> > bian(n+10, vector<int>());
    // vector<LL> du(n+10,0);
    LL ans = 0;
    for (int i=1; i<n; i++) {
        int u, v;  cin >> u >> v;
        // du[u] ++;  du[v] ++;
        bian[u].push_back(v);
        bian[v].push_back(u);
    }
    // for (int i=1; i<=n; i++) {
    //     ans += max((LL)0, a[i] - du[i] * c);
    // }
    vector<int> bo(n+10, 0);
    array<LL, 2> fans = dfs(1, bian, bo, a);
    ans = max(fans[0], fans[1]);
    // ans = max({fans[0], fans[1], fans[2], fans[3]});
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
