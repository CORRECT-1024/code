#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<int> a(n+10);
    vector<vector<int> > b(110, vector<int>());
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        b[a[i]].push_back(i);
    }
    int ans = 0;
    for (int sum=2; sum <= 200; sum++) {
        vector<int> dp(n+10, 0);
        for (int i=1; i<=n; i++) {
            dp[i] = max(dp[i], dp[i-1]);
            int to = sum - a[i];
            if (to <= 0 || to > 100 || (int)b[to].size() == 0)  continue;
            int l = 0, r = b[to].size()-1;
            while (l < r) {
                int mid = ((l + r - 1) >> 1);
                if (b[to][mid] > i) r = mid;
                else l = mid + 1;
            }
            if (b[to][l] <= i)  continue;
            dp[b[to][l]] = max(dp[b[to][l]], dp[i-1] + 1);
        }
        ans = max(ans, dp[n]);
    }
    cout << ans * 2 << '\n';
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
