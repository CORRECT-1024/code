#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 2> > a(m+10);
    for (int i=1; i<=m; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    sort(&a[1], &a[m+1], [&](array<int, 2>&x, array<int, 2>&y) {
        return x[0] < y[0];
    });
    vector<int> b(n+10, -1);
    int id = 1, r0 = -1, mxr = -1;
    bool boans = true;
    for (int i=1; i<=n; i++) {
        // if (i < a[id][0] )  continue;
        while (id <= n && i == a[id][0]) {
            r0 = max(r0, i);
            mxr = max(mxr, a[id][1]);
            if (id < n && mxr >= a[id+1][0]) {
                r0 = max(r0, a[id+1][0]);
            }
            id ++;
        }
        if (i <= r0) {
            b[i] = 0;
        }
    }
    for (int i=1; i<=m; i++) {
        swap(a[i][0], a[i][1]);
        a[i][0] = n + 1 - a[i][0];
        a[i][1] = n + 1 - a[i][1];
    }
    sort(&a[1], &a[m+1], [&](array<int, 2>&x, array<int, 2>&y) {
        return x[0] < y[0];
    });
    // for (int i=1; i<=m; i++) {
    //     cout << a[i][0] << ' '<< a[i][1] << '\n';
    // }
    // cout << '\n';
    id = 1; r0 = -1;  mxr = -1;
    for (int i=1; i<=n; i++) {
        // if (i < a[id][0] )  continue;
        while (id <= n && i == a[id][0]) {
            r0 = max(r0, i);
            mxr = max(mxr, a[id][1]);
            if (id < n && mxr >= a[id+1][0]) {
                r0 = max(r0, a[id+1][0]);
            }
            id ++;
        }
        if (i <= r0) {
            if (b[n + 1 - i] == 0) {
                boans = false;
                break;
            }
            b[n + 1 - i] = 1;
        }
    }
    if (! boans ) {
        cout << -1 << '\n';
        return;
    }
    // for (int i=1; i<=n; i++) {
    //     cout << b[i] << ' ';
    // }
    // cout << '\n';
    vector<vector<LL> > dp(n+10, vector<LL> (n+10, 0));
    dp[0][0] = 0;
    int p = 0;
    for (int i=1; i<=n; i++) {
        if (b[i] == 0) {
            for (int j=0; j<=p; j++) {
                dp[i][j] = dp[i-1][j] + j;
            }
        } else if (b[i] == 1) {
            for (int j=0; j<=p; j++) {
                dp[i][j+1] = dp[i-1][j];
            }
            p ++;
        } else {
            for (int j=0; j<=p; j++) {
                dp[i][j] = max(dp[i-1][j] + j, dp[i][j]);
                dp[i][j + 1] = dp[i-1][j];
            }
            p ++;
        }
        // for (int j=0; j<=p; j++) {
        //     cout << dp[i][j] << ' ';
        // }
        // cout << '\n';
    }
    LL ans = 0;
    int l = 0, r = n;
    for (int i=0; i<=n; i++) {
        if (b[i] == 0) r --;
        else if (b[i] == 1) l ++;
    }
    for (int i=l; i<=r; i++) {
        LL num = 0;
        if (i) num += i * (i - 1) / 2;
        if (i != n) num += (n - i) * (n - i - 1) / 2;
        num += dp[n][i];
        ans = max(ans, num);
    }
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
