#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

bool check(int x, int n, vector<int>&a, vector<int>&b) {
    vector<array<int, 3> > dp(n + 10, {0, 0, 0});
    for (int i=1; i<=n; i++) {
        if (a[i] >= x) {
            dp[i][0] = dp[i-1][0] + 1;
            dp[i][2] = max(dp[i-1][1], dp[i-1][2]) + 1;
        } else {
            dp[i][0] = dp[i-1][0];
            dp[i][2] = max(dp[i-1][1], dp[i-1][2]);
        }
        if (b[i] >= x) {
            dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + 1;
        } else {
            dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
        }
    }
    int num = max({dp[n][0], dp[n][1], dp[n][2]});
    return num >= (n + 1) / 2;
}
void work() {
    int n;
    cin >> n;
    vector<int> a(n+10, 0), b(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i] >> b[i];
    }
    int l = 0, r = 1e9;
    while (l < r) {
        int mid = ((l + r + 1) >> 1);
        if (check(mid, n, a, b) ) l = mid;
        else r = mid - 1;
    }
    cout << l << '\n';
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
    while(T--) {
        work();
    }

   return 0;
}
