#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, k;
    cin >> n >> k;
    vector<array<int, 2> > a(n+10);
    for (int i=1; i<=n; i++) {
        cin >> a[i][0] >> a[i][1];
        if (a[i][0] > a[i][1]) swap(a[i][0], a[i][1]);
    }
    vector<int> dp(k+10, 1e9);
    dp[0] = 0;
    for (int i=1; i<=n; i++) {
        int x = a[i][0], y = a[i][1];
        int sum = 0;
        vector<int> fdp(dp);
        for (int j=1; j<=a[i][0] + a[i][1]; j++) {
            if (x <= y) {
                sum += x;  y --;
            } else {
                sum += y;  x --;
            }
            for (int num = 0; num < k; num ++) {
                int to = num + j;
                if (to > k) to = k;
                fdp[to] = min(fdp[to], dp[num] + sum);
            }
        }
        dp = fdp;
    }
    if (dp[k] == 1e9)  dp[k] = -1;
    cout << dp[k] << '\n';
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
