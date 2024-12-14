#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

LL dfs(LL num, LL id, vector<LL>&a, LL len, vector<vector<int> > &to) {
    num += a[id];  len ++;
    LL ans = num / len;
    // cout << ans << '\n';
    for (auto &toid : to[id]) {
        ans += dfs(num, toid, a, len, to);
    }
    return ans;
}
void work() {
    LL x, y, hp;
    cin >> x >> y >> hp;
    LL xans = 0, yans = 0;
    vector<LL> a;
    for (int i=1; i*i <= x; i++) {
        if (x % i)  continue;
        a.push_back(i);
        if (i * i != x) a.push_back(x / i);
    }
    sort(a.begin(), a.end(), [&](int x, int y) {
        return x > y;
    });
    vector<vector<int> > to(a.size(), vector<int>());
    for (int i=0; i<a.size()-1; i++) {
        for (int j=i+1; j<a.size(); j++) {
            if (a[i] % a[j])  continue;
            to[i].push_back(j);
        }
    }
    xans = dfs(0, 0, a, 0, to);
    a.clear();
    for (int i=1; i*i <= y; i++) {
        if (y % i)  continue;
        a.push_back(i);
        if (i * i != y) a.push_back(y / i);
    }
    sort(a.begin(), a.end(), [&](int x, int y) {
        return x > y;
    });
    to = vector<vector<int> > (a.size(), vector<int>());
    for (int i=0; i<a.size()-1; i++) {
        for (int j=i+1; j<a.size(); j++) {
            if (a[i] % a[j])  continue;
            to[i].push_back(j);
        }
    }
    yans = dfs(0, 0, a, 0, to);
    // cout << xans << ' ' << yans << '\n';
    if (xans + yans >= hp) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
    // cin >> T;
    while(T--) {
        work();
    }

   return 0;
}
