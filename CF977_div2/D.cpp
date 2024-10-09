#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, m;
    cin >> n >> m;
    vector<vector<LL> > a(n+10, vector<LL> (m+10)), sum(a), fum(a);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> a[i][j];
            sum[i][j] = sum[i][j-1] + a[i][j];
        }
        for (int j=n; j>=1; j--) {
            fsum[i][j] = fsum[i][j+1] + a[i][j];
        }
    }
    vector<vector<LL> > dp(2, vector<LL> (m+10, 0)), fdp(dp);
    for (int i=1; i<=n; i++) {
        LL mi = 0, p = i % 2;
        for (int j=1; j<=m; j++) {
            dp[p][j] = sum[i][j] - mi;
            mi = min(mi, sum[i][j-1]);
        }
        
    }

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
