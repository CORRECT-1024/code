#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, m;
    cin >> n >> m;
    vector<LL> a(n+10, 0), now(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        now[i] = a[i];
    }
    vector<array<LL, 2> > b(m+10, {0});
    vector<vector<int> > id(n+10, vector<int>());
    for (int i=1; i<=m; i++) {
        cin >> b[i][0] >> b[i][1];
        id[b[i][1]].push_back(i);
    }
    LL num = 0;
    for (int i=1; i<=n; i++) {
        if (id[i].size() == 0) {
            num += a[i];
            now[i] = 0;
        }
    }
    priority_queue<int, vector<int>, greater<> > pri;
    for (int i=1; i<=m; i++) {
        pri.push(i);
    }
    LL ans = 0, la = 0;
    for (int i=1; i<=m; i++) {
        LL d = b[i][0] - la;
        while (!pri.empty()) {
            if (pri.top() < i) pri.pop();
            else break;
        }
        while (d > 0 && !pri.empty()) {
            int fid = b[pri.top()][1];
            LL fd = min(d, now[fid]);
            d -= fd;
            ans += fd;
            now[fid] -= fd;
            while (!pri.empty() && now[b[pri.top()][1]] == 0)  pri.pop();
        }
        if (d > 0) {
            if (num < d) {
                ans += num;
                num = 0;
                break;
            }
            ans += d;
            num -= d;
        }
        now[b[i][1]] = a[b[i][1]];
        int l = 0, r = id[b[i][1]].size()-1;
        while (l < r) {
            int mid = ((l + r - 1) >> 1);
            if (id[b[i][1]][mid] > i) r = mid;
            else l = mid + 1;
        }
        if (id[b[i][1]][l] <= i) {
            num += now[b[i][1]];
            now[b[i][1]] = 0;
        } else {
            pri.push(id[b[i][1]][l]);
        }
        la = b[i][0];
    }
    while (!pri.empty()) {
        ans += now[b[pri.top()][1]];
        now[b[pri.top()][1]] = 0;
        pri.pop();
    }
    ans += num;
    cout << ans << '\n';
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