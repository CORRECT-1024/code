#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

int find(int x, vector<int> &fa) {
    if (fa[x] == x)  return x;
    return fa[x] = find(fa[x], fa);
}
void work() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> bian(m+10, vector<int>()), a(n+10, vector<int>());
    for (int i=1; i<=n; i++) {
        int num;  cin >> num;
        for (int j=1; j<=num; j++) {
            int x;  cin >> x;
            a[i].push_back(x);
            bian[x].push_back(i);
        }
    }
    // vector<int> fa(m+10, 0);
    // for (int i=1; i<=m; i++)  fa[i] = i;
    // for (int i=1; i<=n; i++) {
    //     int fid = i;
    //     for (auto&p : a[i]) {
    //         fid = min(fid, find(p, fa));
    //     }
    //     for (auto&p : a[i]) {
    //         fa[fa[p]] = fid;
    //     }
    // }
    // int boid = 0;
    // int id1 = find(a[1][0], fa);
    // for (int i=1; i<=n; i++) {
    //     if (find(a[i][0], fa) != id1) {
    //         boid = i;  break;
    //     }
    // }
    // if (boid ) {
    //     cout << "Yes\n";
    //     cout << boid;
    //     for (int i=1; i<=n; i++) {
    //         if (i == boid )  continue;
    //         cout << ' ' << i;
    //     }
    //     cout << '\n';
    //     return;
    // }
    // vector<int> bo(n+10,0);
    // for (int i=1; i<=m; i++) {
    //     if (bian[i].size() ) {
    //         bo[bian[i][bian[i].size()-1]] = i;
    //     }
    // }
    // for (int i=2; i<=n; i++) {
    //     if (!bo[i] ) {
    //         boid = i;   break;
    //     }
    // }
    // if (boid ) {
    //     cout << "Yes\n";
    //     cout << boid;
    //     for (int i=1; i<=n; i++) {
    //         if (i == boid )  continue;
    //         cout << ' ' << i;
    //     }
    //     cout << '\n';
    //     return;
    // }
    int id = 0, to = 0;
    for (int i=1; i<=n; i++) {
        int l = 1, r = n;
        for (auto &p : a[i]) {
            if (i == bian[p][bian[p].size()-1]) {
                int fid = (bian[p].size() > 1 ? bian[p][bian[p].size()-2] + 1 : 1);
                l = max(l, fid);
            } else {
                r = min(r, bian[p][bian[p].size()-1] - 1);
            }
        }
        if (l != i) {
            id = i;  to = l;  break;
        } else if (r != i) {
            id = i;  to = r;  break;
        }
    }
    if (id) {
        cout << "Yes\n";
        bool bo = true;
        vector<int> ans(n+10, 0);
        ans[to] = id;
        int fid = 1;
        int num = 1;
        while (fid <= n) {
            if (ans[fid]) {
                fid ++;  continue;
            }
            if (num == id) num ++;
            ans[fid] = num;
            num ++;  fid ++;
        }
        for (int i=1; i<=n; i++) {
            if (i > 1)  cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
        return;
    }
    cout << "No\n";
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
