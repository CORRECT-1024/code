#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<LL> a(n+10);
    vector<array<LL, 2> > b;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if (i > 1) {
            b.push_back({a[i] - (n + 1 - i), a[i] - (n + 1 - i) + i - 1});
            // cout << a[i] - (n + 1 - i) << ' ' << a[i] - (n + 1 - i) + i - 1 << '\n';
        }
    }
    sort(b.begin(), b.end());
    map<LL, int> mp;
    mp[0] = 1;
    LL ans = 0;
    // queue<LL> qu;
    priority_queue<LL, vector<LL>, greater<> > qu;
    qu.push(0);
    int id = 0;
    while (!qu.empty() ) {
        LL t = qu.top();  qu.pop();
        ans = max(ans, t);
        while (id < b.size() && b[id][0] < t) id ++;
        while (id < b.size() && b[id][0] == t) {
            if (mp[b[id][1] ] ) {
                id ++;  continue;
            }
            // cout << "***" << b[id][1] << '\n';
            qu.push(b[id][1]);
            mp[b[id][1]] = 1;
            id ++;
        }
    }
    ans += n;
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
