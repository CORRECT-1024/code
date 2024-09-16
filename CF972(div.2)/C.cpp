#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define QHK 1

void work() {
    int n, len;
    cin >> n >> len;
    vector<string > s(n+10);
    for (int i=1; i<=n; i++) {
        cin >> s[i];
    }
    vector<vector<int> > dp(n+10, vector<int> (10, -1e9));
    vector<int> bo(10, 0);
    bo[0] = 1;  dp[0][0] = 0;
    for (int i=1; i<=n; i++) {
        vector<pair<int, int> > fdp(10);
        for (int j=0; j<5; j++) {
            fdp[j].first = j % 5;  fdp[j].second = 0;
        }
        for (int j=0; j<s[i].size(); j++) {
            int k = -1;
            if (s[i][j] == 'n')  k = 0;
            else if (s[i][j] == 'a')  k = 1;
            else if (s[i][j] == 'r')  k = 2;
            else if (s[i][j] == 'e')  k = 3;
            else if (s[i][j] == 'k')  k = 4;
            if (k == -1)  continue;
            for (int l = 0; l<5; l++) {
                if (fdp[l].first == k) {
                    fdp[l].second ++;
                    fdp[l].first = (fdp[l].first + 1) % 5;
                } else {
                    fdp[l].second --;
                }
            }
        }
        for (int j=0; j<5; j++) dp[i][j] = dp[i-1][j];
        for (int j=0; j<5; j++) {
            // cout << fdp[j].first << ' ' << fdp[j].second << '\n';
            if (!bo[j] ) continue;
            if (dp[i-1][j] + fdp[j].second > dp[i][fdp[j].first]) {
                dp[i][fdp[j].first] = dp[i-1][j] + fdp[j].second;
                bo[fdp[j].first] = 1;
                // cout << fdp[j].first << ": " << dp[i][fdp[j].first] << '\n';
            }
        }
        // cout << '\n';
    }
    int ans = 0;
    for (int i=0; i<5; i++) {
        dp[n][i] -= i * 2;
        ans = max(ans, dp[n][i]);
    }
    cout << ans << '\n';
}
int main()
{
    #ifdef QHK
    freopen("qi.in","r",stdin);
    freopen("qi.out","w",stdout);
    #endif
    // ios::sync_with_stdio(false); cin.tie(0); 
    int T=1;
    // scanf("%d",&T);
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
