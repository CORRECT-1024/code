#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    string be;
    vector<pair<string, int> > ans;
    int la;
    map<string, int> mp;
    mp["N"] = 0;  mp["E"] = 1;
    mp["S"] = 2;  mp["W"] = 3;
    for (int i=1; i<=n; i++) {
        string s;  cin >> s;
        int len;  cin >> len;
        if (i == 1) {
            be = s;  la = mp[s];
        }
        int k = mp[s];
        if (k == la) {
            ans.push_back({"Z", len});
        } else if (k == (la + 1) % 4) {
            ans.push_back({"R", -1});
            ans.push_back({"Z", len});
        } else if (la == (k + 1) % 4) {
            ans.push_back({"L", -1});
            ans.push_back({"Z", len});
        } else {
            ans.push_back({"L", -1});
            ans.push_back({"L", -1});
            ans.push_back({"Z", len});
        }
        la = k;
    }
    cout << ans.size() << ' ' << be << '\n';
    for (int i=0; i<ans.size(); i++) {
        cout << ans[i].first;
        if (ans[i].second != -1) {
            cout << ' ' << ans[i].second;
        }
        cout << '\n';
    }
}
int main()
{
    freopen("qi.in","r",stdin);
    freopen("qi.out","w",stdout);
    ios::sync_with_stdio(false);  cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        work();
    }

    return 0;
}