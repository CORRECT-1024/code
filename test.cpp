#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

vector<int> gameofCheckpoints(int n, vector<vector<int>> oil, vector<vector<int>> water) {
    vector<int> ans(n, -1);
    queue<array<int, 3> > qu;
    // {id, len, oil/water}
    qu.push({0, 0, 0});
    qu.push({0, 0, 1});
    map<array<int, 2> , int> mp;
    mp[{0, 1}] = 0;  mp[{0, 0}] = 0;
    while (!qu.empty()) {
        array<int, 3> p = qu.front();  qu.pop();
        int id = p[0], len = p[1], op = p[2];
        // cout << id << ' ' << len << '\n';
        if (ans[id] == -1) ans[id] = len;
        else ans[id] = min(ans[id], len);
        if (op == 0) {
            for (auto &to : oil[id]) {
                if (mp.find({to, 1 - op}) == mp.end() )  {
                    // cout << to << '\n';
                    mp[{id, 1 - op}] = len + 1;
                    qu.push({to, mp[{id, 1 - op}], 1 - op});
                }
                mp[{id, 1 - op}] = min(mp[{id, 1 - op}], len + 1);
            }
        } else {
            for (auto &to : water[id]) {
                if (mp.find({id, 1 - op}) == mp.end() )  {
                    mp[{id, 1 - op}] = len + 1;
                    qu.push({to, mp[{id, 1 - op}], 1 - op});
                }
                mp[{id, 1 - op}] = min(mp[{id, 1 - op}], len + 1);
            }
        }
    }
    return ans;
}
int main()
{
    #ifdef QHK
    freopen("qi.in","r",stdin);
    freopen("qi.out","w",stdout);
    #endif
    ios::sync_with_stdio(false); cin.tie(0); 
    
    int n;
    cin >> n;
    vector<vector<int> > bian1(n, vector<int>()), bian2(n, vector<int>());
    int num;  cin >> num;
    int op ;  cin >> op;
    for (int i=1; i<=num; i++) {
        int u, v;  cin >> u >> v;
        bian1[u].push_back(v);
    }
    cin >> num >> op;
    for (int i=1; i<=num; i++) {
        int u, v;  cin >> u >> v;
        bian2[u].push_back(v);
    }
    vector<int> ans = gameofCheckpoints(n, bian1, bian2);
    for (auto & ansi : ans) {
        cout << ansi << '\n';
    }

    return 0;
}
