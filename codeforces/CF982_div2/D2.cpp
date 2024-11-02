#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int mod = 1e9 + 7;
const int mod1 = 1e9 + 9;

array<LL, 3> fun(array<LL, 3> x, array<LL, 3> y) {
    if (x[0] == y[0]) {
        return {x[0], (x[1] + y[1]) % mod, (x[2] + y[2]) % mod1};
    }
    // return min(x, y);
    if (x[0] < y[0])  return x;
    return y;
}
void work() {
    int n, m;
    cin >> n >> m;
    vector<LL> a(n+10, 0), b(m+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    vector<LL> sum(n+10, 0);
    for (int i=1; i<=n; i++) {
        sum[i] = sum[i-1] + a[i];
    }
    for (int i=1; i<=m; i++)  cin >> b[i];
    vector<vector<array<LL, 3> > > dp(n+10, vector<array<LL, 3> > (m+10, {(LL)1e18, (LL)0, (LL)0}));
    // for (int i=1; i<=m; i++)  dp[0][i] = {0, 1};
    dp[0][0] = {0, 1, 1};
    vector<priority_queue<LL, vector<LL>, greater<> > > pri(m+10, priority_queue<LL, vector<LL>, greater<> >());
    vector<map<LL, LL> > num(m+10, map<LL, LL>());
    vector<map<LL, LL> > num1(m+10, map<LL, LL>());
    priority_queue<array<LL, 5>, vector<array<LL, 5> > , greater<> > del;
    for (int i=1; i<=n; i++) {
        if (b[1] < a[i]) {
            cout << -1 << '\n';
            return;
        }
        while (!del.empty() && del.top()[0] < i) {
            array<LL, 5> to = del.top();  del.pop();
            num[to[1]][to[2]] += mod - to[3];
            num[to[1]][to[2]] %= mod;
            num1[to[1]][to[2]] += mod1 - to[4];
            num1[to[1]][to[2]] %= mod1;
        }
        for (int j=1; j<=m; j++) {
            while (!pri[j].empty() && num[j][pri[j].top()] == 0 && num1[j][pri[j].top()] == 0) {
                pri[j].pop();
            }
            if (!pri[j].empty()) dp[i-1][j] = fun(dp[i-1][j], {pri[j].top(), num[j][pri[j].top()], num1[j][pri[j].top()]});
            dp[i-1][j] = fun(dp[i-1][j], dp[i-1][j-1]);
        }
        // if (i == n + 1) break;
        int l = 1, r = m;
        while (l < r) {
            int mid = ((l + r + 1) >> 1);
            if (b[mid] >= a[i]) l = mid;
            else r = mid - 1;
        }
        for (int j=1; j<=l; j++) {
            if (dp[i-1][j][0] == (LL)1e18)  continue;
            int l = i, r = n;
            while (l < r) {
                int mid = ((l + r + 1) >> 1);
                if (sum[mid] - sum[i-1] <= b[j]) l = mid;
                else r = mid - 1;
            }
            pri[j].push(dp[i-1][j][0] + m - j);
            num[j][dp[i-1][j][0] + m - j] = (num[j][dp[i-1][j][0] + m - j] + dp[i-1][j][1]) % mod;
            num1[j][dp[i-1][j][0] + m - j] = (num1[j][dp[i-1][j][0] + m - j] + dp[i-1][j][2]) % mod1;
            del.push({r + 1, j, dp[i-1][j][0] + m - j, dp[i-1][j][1], dp[i-1][j][2]});
        }
    }
    while (!del.empty() && del.top()[0] <= n) {
        array<LL, 5> to = del.top();  del.pop();
        num[to[1]][to[2]] += mod - to[3];
        num[to[1]][to[2]] %= mod;
        num1[to[1]][to[2]] += mod1 - to[4];
        num1[to[1]][to[2]] %= mod1;
    }
    for (int j=1; j<=m; j++) {
        while (!pri[j].empty() && num[j][pri[j].top()] == 0 && num1[j][pri[j].top()] == 0) {
            pri[j].pop();
        }
        if (!pri[j].empty()) dp[n][j] = fun(dp[n][j], {pri[j].top(), num[j][pri[j].top()], num1[j][pri[j].top()]});
        // dp[i-1][j] = fun(dp[i-1][j], dp[i-1][j-1]);
    }
    array<LL, 3> ans = {(LL)1e18, (LL)0};
    for (int i=1; i<=m; i++) {
        // cout << dp[n][i][0] << ' ' << dp[n][i][1] << '\n';
        ans = fun(ans, dp[n][i]);
    }
    cout << ans[0] << ' ' << ans[1] << '\n';
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
    while(T--){
        work();
    }

   return 0;
}
