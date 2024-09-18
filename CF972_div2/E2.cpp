#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int l, n, m;
    cin >> l >> n >> m;
    vector<int> a(l+10, 0);
    for (int i=1; i<=l; i++)  cin >> a[i];
    vector<vector<int> > b(n+10, vector<int>(m+10));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> b[i][j];
        }
    }
    if (n > m) {
        vector<vector<int> > bb(m+10, vector<int> (n+10));
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                bb[j][i] = b[i][j];
            }
        }
        swap(n, m);
        swap(b, bb);
    }
    vector<vector<array<int, 2> > > id(n*m + 10); 
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            id[b[i][j]].push_back({i, j});
        }
    }
    l = min(l, n); 
    vector<int> f(n+10, 0);
    for (int i=l; i>=1; i--) {
        int lastf = 0;
        // cout << a[i] << "***: \n";
        for (int j=n; j>=1; j--) {
            // cout << j << ":\n";
            // 现在的f[j+1] = f[i][j+1]  j+1行的必胜态，对于j行也是必胜态
            int nowf = f[j+1];
            // cout << "***" << f[j+1] << "&&\n";
            auto it = upper_bound(id[a[i]].begin(), id[a[i]].end(), array{j, m});
            if (it != id[a[i]].begin()) {
                it --;
                // if ((*it)[0] == j) cout << (*it)[0] << ' ' << (*it)[1] << '\n';
                if ((*it)[0] == j && (*it)[1] >= lastf) {
                    // it是j行最后一个a[i] 
                    // lastf = f[i-1][j+1]  新的必胜态需要>=lastf
                    nowf = max(nowf, (*it)[1]);
                }
            }
            lastf = f[j];
            f[j] = nowf;
            // cout << "**" << nowf << ' ' << lastf << '\n';
        }
    }
    // cout << f[1] << '\n';
    if (f[1] == 0) {
        cout << "N\n";
    } else {
        cout << "T\n";
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
