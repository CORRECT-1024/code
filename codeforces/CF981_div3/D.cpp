#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<LL> a(n+10, 0);
    vector<array<LL, 2>> sum(n+10, {0, 0});
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        sum[i][0] = sum[i-1][0] + a[i];
        sum[i][1] = i;
    }
    sort(&sum[0], &sum[n+1]);
    vector<vector<int> > bian(n+10, vector<int>());
    for (int i=1; i<=n; i++) {
        if (sum[i][0] != sum[i-1][0])  continue;
        bian[sum[i-1][1]].push_back(sum[i][1]);
    }
    vector<int> dp(n+10, 0);
    for (int i=0; i<=n; i++) {
        if (i ) dp[i] = max(dp[i], dp[i-1]);
        if (bian[i].size() )  dp[bian[i][0]] = max(dp[bian[i][0]], dp[i] + 1);
    }
    cout << dp[n] << '\n';
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
