#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

int n, m;

bool fun(int x, int y, vector<string> &s) {
    if (x <= 0 || x > n || y <= 0 || y > m) return false;
    if (s[x][y] == '.')  return true;
    return false;
}
void dfs(int x, int y, int val, vector<string > &s, vector<vector<int> > &a, vector<vector<int> > &b, vector<int> &num) {
    a[x][y] = val;
    if (b[x][y] )  return;
    num[val] ++;  b[x][y] = 1;
    // cout << x << ' ' << y << ' ' << val << '\n';
    if (fun(x - 1, y, s))  dfs(x - 1, y, val, s, a, b, num);
    if (fun(x + 1, y, s)) dfs(x + 1, y, val, s, a, b, num);
    if (fun(x, y - 1, s))  dfs(x, y - 1, val, s, a, b, num);
    if (fun(x, y + 1, s)) dfs(x, y + 1, val, s, a, b, num);
}
void work() {
    cin >> n >> m;
    vector<string> s(n+10);
    for (int i=1; i<=n; i++) {
        cin >> s[i];
        s[i] = " " + s[i];
    }
    vector<vector<int> > a(n+10, vector<int>(m+10, 0)), b(n+10, vector<int>(m+10, 0));
    vector<array<int, 2> > dian;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (s[i][j] == '.') {
                a[i][j] = i * m + j;
                dian.push_back({i, j});
            }
        }
    }
    vector<array<int, 2> > id;
    vector<int> num((n + 10) * (m + 10) + 10, 0);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (!a[i][j] )  continue;
            if (!b[i][j]) {
                id.push_back({i, j});
                dfs(i, j, i * m + j, s, a, b, num);
            }
        }
    }
    int ans = 0;
    for (int i=0; i<id.size(); i++) {
        // cout << i << '\n';
        // cout << id[i][0] << ' ' << id[i][1] << ' ';
        // cout << num[id[i][0] * m + id[i][1]]  << '\n';
        int x = id[i][0], y = id[i][1];
        vector<int> bo(dian.size() + 10, 0);
        for (int j=0; j<dian.size(); j++) {
            if (a[id[i][0]][id[i][1]] == a[dian[j][0]][dian[j][1]]) {
                bo[j] = 1;
            }
        }
        map<array<int, 2> , int> mp;
        queue<array<int, 2> > qu;
        qu.push({0, 0});  mp[{0, 0}] = 1;
        while (!qu.empty()) {
            auto [dx, dy] = qu.front();  qu.pop();
            for (int j=0; j<dian.size(); j++) {
                if (bo[j] )  continue;
                if (!fun(dian[j][0]+dx, dian[j][1]+dy, s) ) {
                    bo[j] = 1;
                }
            }
            int fx = id[i][0] + dx, fy = id[i][1] + dy;
            if (fun(fx + 1, fy, s) && !mp[{dx + 1, dy}]) {
                qu.push({dx + 1, dy});  mp[{dx + 1, dy}] = 1;
            }
            if (fun(fx - 1, fy, s) && !mp[{dx - 1, dy}]) {
                qu.push({dx - 1, dy});  mp[{dx - 1, dy}] = 1;
            }
            if (fun(fx, fy + 1, s) && !mp[{dx, dy + 1}]) {
                qu.push({dx, dy + 1});  mp[{dx, dy + 1}] = 1;
            }
            if (fun(fx, fy - 1, s) && !mp[{dx, dy - 1}]) {
                qu.push({dx, dy - 1});  mp[{dx, dy - 1}] = 1;
            }
        }
        bool fbo = true;
        for (int j=0; j<dian.size(); j++) {
            if (bo[j] )  continue;
            fbo = false;  break;
        }
        if (fbo) {
            ans += num[id[i][0] * m + id[i][1]];
            // cout << id[i][0] << ' ' << id[i][1] << ' ';
            // cout << num[id[i][0] * m + id[i][1]]  << '\n';
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
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
