#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> pid(p+10, 0);
    for (int i=1; i<=p; i++) {
        cin >> pid[i];
    }
    vector<vector<vector<LL>>> an(2, vector<vector<LL>>(n+10, vector<LL>(n+10, 1e15)));
    for (int i=1; i<=m; i++) {
        LL a, b, c;
        cin >> a >> b >> c;
        an[0][a][b] = min(an[0][a][b], c);
        an[0][b][a] = min(an[0][b][a], c);
    }
    for (int k = 1; k <= n; k++) {
        int fk = k % 2, lk = 1 - fk;
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                an[fk][x][y] = min(an[lk][x][y], max(an[lk][x][k], an[lk][k][y]) );
            }
        }
    }
    int k = n % 2;
    for (int i=1; i<=n; i++) {
        an[k][i][i] = 0;
    }
    // for (int i=1; i<=n; i++) {
    //     for (int j=1; j<=n; j++) {
    //         cout << an[n][i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // return;
    vector<LL> ans(p+10, 1e9);
    LL sum = 1e15, id = 0;
    for (int i=1; i<=n; i++) {
        LL fsum = 0;
        for (int j=1; j<=p; j++) {
            fsum += an[k][i][pid[j]];
        }
        if (fsum < sum) {
            sum = fsum;  id = i;
        }
    }
    for (int i=1; i<=p; i++) {
        ans[i] = an[k][id][pid[i]];
        // sum += ans[i];
        // cout << ans[i] << '\n';
    }
    cout << sum << ' ';
    // return;
    vector<int> bo(n+10, 0);
    bo[id] = 1;
    for (int num=2; num<=n; num ++) {
        int to = -1;  LL fsum = -1;
        for (int i=1; i<=n; i++) {
            if (bo[i] )  continue;
            LL ffsum = 0;
            for (int j=1; j<=p; j++) {
                if (an[k][i][pid[j]] < ans[j]) {
                    ffsum += ans[j] - an[k][i][pid[j]];
                }
            }
            if (ffsum > fsum) {
                fsum = ffsum;  to = i;
            }
        }
        bo[to] = 1;
        for (int j=1; j<=p; j++) {
            if (an[k][to][pid[j]] < ans[j]) {
                ans[j] = an[k][to][pid[j]];
            }
        }
        sum -= fsum;
        cout << sum << ' ';
    }
    cout << '\n';
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
