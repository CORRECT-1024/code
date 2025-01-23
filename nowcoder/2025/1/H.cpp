#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

bool cmp(array<int, 3> &x, array<int, 3> &y) {
    return x[1] < y[1];
}
void work() {
    int n;
    cin >> n;
    vector<array<int, 3> > a(n+10);
    for (int i=1; i<=n; i++) {
        int l, r; cin >> l >> r;
        a[i][0] = r;  a[i][1] = l;  // pri
        a[i][2] = i;
    }
    sort(&a[1], &a[n+1], cmp);
    priority_queue<array<int, 3>, vector<array<int, 3> > , greater<> > pri;
    vector<int> ans(n+10, 0);
    int id = 0;
    for (int i=1; i<=n; i++) {
        while (id < n && a[id + 1][1] <= i) {
            id ++;
            pri.push(a[id]);
        }
        if (pri.empty()) {
            cout << -1 << '\n';
            return;
        }
        ans[pri.top()[2]] = i;
        if (pri.top()[0] < i) {
            cout << -1 << '\n';
            return;
        }
        pri.pop();
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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
