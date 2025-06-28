#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<array<LL, 2> > a(n+10);
    for (int i=1; i<=n; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][1] += a[i][0];
    }
    sort(&a[1], &a[n+1], [&](array<LL, 2> &x, array<LL, 2> &y) {
        return x[0] < y[0];
    });
    vector<array<LL, 3> > b(n+10);
    vector<int> vis(n+10, 0), del(vis);
    for (int i=1; i<=n; i++) {
        b[i][0] = a[i][0];  b[i][1] = a[i][1];  b[i][2] = i;
    }
    sort(&b[1], &b[n+1], [&](array<LL, 3> &x, array<LL, 3> &y) {
        return x[1] < y[1];
    });
    priority_queue<array<LL, 2>, vector<array<LL, 2> >, less<> > pri;
    LL ans = -1;
    int id1 = 0, id2 = 0;
    LL lastnum = -1;
    for (int i=1; i<=n; i++) {
        if (vis[i] ) {
            lastnum = max(lastnum, a[i][1]);
            continue;
        }
        LL num = a[i][0];
        vis[i] = 1;  del[i] = 1;
        while (true) {
            while (id1 < n && a[id1 + 1][0] <= num) {
                id1 ++;  vis[id1] = 1;
                if (!del[id1] )  pri.push({a[id1][1], id1});
            }
            while (id2 < n && (del[ b[id2 + 1][2] ] || b[id2 + 1][1] <= num)) {
                id2 ++;
                del[b[id2][2]] = 1;  vis[b[id2][2]] = 1;
            }
            while (!pri.empty() && (del[ pri.top()[1] ] || pri.top()[0] <= num) ) {
                pri.pop();
            }
            if (pri.empty() ) {
                ans = max(ans, num);
                break;
            }
            num = pri.top()[0];
            while (!pri.empty() )  pri.pop();
        }
        if (a[i][1] >= lastnum) {
            lastnum = a[i][1];
        }
        pri.push({lastnum, 0});
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
