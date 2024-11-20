#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    vector<array<int, 3> > qu;
    map<int, int> mp;
    for (int i=1; i<=n; i++) {
        if (i - 1 >= mp[a[i]] + 1)  qu.push_back({mp[a[i]] + 1, i - 1, a[i]});
        mp[a[i]] = i;
    }
    for (auto &[ai, id] : mp) {
        if (id == n) continue;
        qu.push_back({id + 1, n, ai});
    }
    int endm = m + 1;
    for (int i=1; i<=m; i++) {
        if (mp.find(i) == mp.end()) {
            endm = i;  break;
        }
    }
    vector<array<int, 3> > qqu;
    for (auto&p : qu) {
        if (p[2] < endm) {
            qqu.push_back(p);
        }
    }
    swap(qu, qqu);
    int q = qu.size();
    int len = ceil(sqrt(n));
    sort(qu.begin(), qu.end(), [&](array<int, 3> &x, array<int, 3> &y) {
        if ((x[0] + len - 2)/len == (y[0] + len - 2)/len) {
            return x[1] < y[1];
        }
        return (x[0] + len - 2)/len < (y[0] + len - 2)/len;
    });
    int ans = 0, num = 0;
    map<int, int> to;
    for (auto&[ai, id] : mp) {
        ans ++;
        to[ai] = ans;
    }
    int ainum = ans;
    ans -= endm;
    for (int i=1; i<=n; i++) {
        a[i] = to[a[i]];
    }
    int l, r;
    vector<int> b(ainum+10, 0);
    for (int i=0; i<q; i++) {
        // cout << qu[i][0] << ' ' << qu[i][1] << ' ' << qu[i][2] << '\n';
        if (i == 0 || (qu[i][0] + len - 2)/len != (qu[i-1][0] + len - 2)/len) {
            l = qu[i][0];   r = qu[i][0] - 1;
            // b = vector<int>(n+10, 0);
            for (int j=0; j<=ainum; j++)  b[j] = 0;
            num = 0;
        }
        while (r < qu[i][1]) {
            r ++;
            if (b[a[r]] == 0) num ++;
            b[a[r]] ++;
        }
        while (l != qu[i][0]) {
            if (l > qu[i][0]) {
                l --;
                if (b[a[l]] == 0) num ++;
                b[a[l]] ++;
            } else {
                b[a[l]] --;
                if (b[a[l]] == 0) num --;
                l ++;
            }
        }
        ans = max(ans, num - qu[i][2]);
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
    while(T--) {
        work();
    }

   return 0;
}
