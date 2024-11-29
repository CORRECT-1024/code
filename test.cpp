#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<string> s(n+10);
    for (int i=1; i<=n; i++) {
        cin >> s[i];
    }
    string str;
    cin >> str;
    vector<vector<pair<string, int> > > fs(60, vector<pair<string, int> > ());
    fs[str.size()].push_back({str, 0});
    map<pair<string, int>, int> mp;
    mp[{str, 0}] = 1;
    int ans = 0;
    for (int siz = 55; siz >= 0; siz --) {
        for (auto &[ss, num] : fs[siz]) {
            ans = max(ans, num);
            // cout << ss << ' ' << num << '\n';
            for (int i=1; i<=n; i++) {
                for (int id = 0; id+(int)s[i].size() <= siz; id++) {
                    if (ss.substr(id, s[i].size()) == s[i]) {
                        string news = ss.substr(0, id) + ss.substr(id + s[i].size(), ss.size() - id - s[i].size());
                        // cout << ss << '\n' << ss.substr(0, id) << ' ' << s[i] << ' ' << ss.substr(id + s[i].size(), ss.size() - id - s[i].size()) << '\n';
                        int newnum = num + 1;
                        if (mp[{news, newnum} ] )  continue;
                        mp[{news, newnum}] = 1;
                        fs[news.size()].push_back({news, newnum});
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}
int main()
{
    freopen("qi.in","r",stdin);
    freopen("qi.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); 
    int T=1;
    // cin >> T;
    while(T--) {
        work();
    }

   return 0;
}
