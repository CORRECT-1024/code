#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void add(char c, int x, vector<vector<int> > &a) {
    if (c == 'B') a[1].push_back(x);
    else if (c == 'G') a[2].push_back(x);
    else if (c == 'R') a[3].push_back(x);
    else if (c == 'Y') a[4].push_back(x);
}
void work() {
    int n, q;
    cin >> n >> q;
    vector<vector<int> > a(10, vector<int> (1, 0));
    vector<vector<int> > b(10, vector<int> (1, 0));
    vector<string> str(n+10);
    for (int i=1; i<=n; i++) {
        string s; cin >> s;
        str[i] = s;
        add(s[0], i, a);
        add(s[1], i, a);
        if (s == "BG") b[1].push_back(i);
        else if (s == "BR") b[2].push_back(i);
        else if (s == "BY") b[3].push_back(i);
        else if (s == "GR") b[4].push_back(i);
        else if (s == "GY") b[5].push_back(i);
        else if (s == "RY") b[6].push_back(i);
    }
    while (q --) {
        int x, y;
        cin >> x >> y;
        // cout << str[x] << ' ' << str[y] << '\n';
        if ((str[x][0] == str[y][0]) || (str[x][0] == str[y][1]) || (str[x][1] == str[y][0]) || (str[x][1] == str[y][1])) {
            cout << abs(x - y) << '\n';
            continue;
        }
        int ans = 1e9;
        if (x > y) swap(x, y);
        for (int i=1; i<=6; i++) {
            if (b[i].size() == 1 || str[b[i][1]] == str[x] || str[b[i][1]] == str[y])  continue;
            int l = 1, r = b[i].size() - 1;
            while (l < r) {
                int mid = ((l + r + 1) >> 1);
                if (b[i][mid] <= x) l = mid;
                else r = mid - 1;
            }
            ans = min(ans, abs(x - b[i][l]) + abs(y - b[i][l]));
            if (l + 1 < b[i].size()) {
                l ++;
                ans = min(ans, abs(x - b[i][l]) + abs(y - b[i][l]));
            }
        }
        if (ans == 1e9) ans = -1;
        cout << ans << '\n';
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
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
