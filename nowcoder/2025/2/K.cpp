#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

int num = 0;
int n, m;

void dfs(int x, int y, vector<string>&s, vector<vector<int> >&a, vector<vector<int> >&b, map<array<int, 2>, int> &mp) {
    if (x < 0 || x >= n || y < 0 || y >= m)  return;
    if (a[x][y] )  return;
    if (s[x][y] == '0') {
        if (mp.find({x, y}) == mp.end())  num ++;
        mp[{x, y}] = 1;  return;
    }
    a[x][y] = 1;
    dfs(x - 1, y, s, a, b, mp);
    dfs(x + 1, y, s, a, b, mp);
    dfs(x, y - 1, s, a, b, mp);
    dfs(x, y + 1, s, a, b, mp);
}
void work() {
    cin >> n >> m;
    vector<string> s(n+10);
    for (int i=0; i<n; i++) {
        cin >> s[i];
    }
    vector<vector<int> > a(n+10, vector<int>(m+10, 0)), b(a);
    int ans = 1e9;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] )  continue;
            if (s[i][j] == '1') {
                map<array<int, 2> , int> mp;
                dfs(i, j, s, a, b, mp);
                ans = min(ans,  num);
                num = 0;
            }
        }
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
    // cin >> T;
    while(T--) {
        work();
    }

   return 0;
}
