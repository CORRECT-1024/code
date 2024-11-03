#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n+10, vector<int> (m+10, 0)), b(a);
    vector<array<int, 2> > beid(n+10, {0, 0});
    for (int i=1; i<=n; i++) {
        string s;  cin >> s;
        for (int j=1; j<=m; j++) {
            a[i][j] = s[j - 1] - '0';
            if (a[i][j] == 1) {
                beid[min({i, j, n - i + 1, m - j + 1})] = {i, j};
            }
        }
    }
    // cout << beid[1][0] << ' ' << beid[1][1] << '\n';
    int x, y, p = 0, ans = 0;
    for (int i=0; i<=m+1; i++) {
        b[0][i] = 1;  b[n+1][i] = 1;
    }
    for (int i=0; i<=n+1; i++) {
        b[i][0] = 1;  b[i][m+1] = 1;
    }
    int t = 1;
    vector<int> c({0, 1, 5, 4, 3, 0});
    int id = 1, en = min((n + 1) / 2, (m + 1) / 2);
    x = beid[id][0], y = beid[id][1];
    if (x == 0) x = 1, y = 0;
    if (a[x][y] == c[t]) t ++;
    b[x][y] = 1;
    while (true ) {
        if (! b[x][y + 1]  && x == id) {
            y ++;
        } else if (! b[x + 1][y] && y == m + 1 - id) {
            x ++;
        } else if (! b[x][y - 1] && x == n + 1 - id) {
            y --;
        } else if (! b[x - 1][y] && y == id) {
            x --;
        } else {
            id ++;
            x = beid[id][0], y = beid[id][1];
            if (x == 0) x = id, y = id;
            t = 1;
            if (b[x][y])  break;
        }
        if (a[x][y] == c[t]) {
            t ++;
        } else {
            t = 1;
        }
        if (t == 5) {
            ans ++;
            t = 1;
        }
        b[x][y] = 1;
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
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
