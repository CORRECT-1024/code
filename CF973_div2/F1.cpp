#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

bool cmp(array<int, 2> x, array<int, 2> y) {
    return min(x[0], x[1]) < min(y[0], y[1]);
}
void work() {
    int n;
    cin >> n;
    vector<array<int, 2> > bian(n+10);
    for (int i=1; i<n; i++) {
        cin >> bian[i][0] >> bian[i][1];
    }
    sort(&bian[1], &bian[n], cmp);
    vector<vector<int> > zi(n+10, vector<int> ());
    vector<int> fa(n+10, 0);
    fa[1] = -1;
    for (int i=1; i<n; i++) {
        int u, v; 
        u = bian[i][0];  v = bian[i][1];
        if (fa[v] != 0)  swap(u, v);
        fa[v] = u;
        zi[u].push_back(v);
    }
    vector<int> bo(n+10, 0);
    int u;  cin >> u;  cin >> u;
    int id = u;
    int nlen = 0;
    while (id > 0) {
        bo[id] = 1;
        nlen ++;
        id = fa[id];
    }
    vector<int> len(n+10, 1);
    queue<int> qu;
    for (int i=1; i<=n; i++) {
        if (zi[i].size() == 0) {
            if (!bo[i]) qu.push(i);
        }
    }
    vector<int> num(n+10, 0);
    while (!qu.empty()) {
        int t = qu.front();  qu.pop();
        len[fa[t]] = max(len[fa[t]], len[t] + 1);
        num[fa[t]] ++;
        if (num[fa[t]] == zi[fa[t]].size() && !bo[fa[t]]) {
            qu.push(fa[t]);
        }
    }
    for (int i=1; i<=n; i++)  len[i] --;
    vector<int> lu(nlen + 10, 0), lv(nlen + 10, 0);
    // cout << nlen << '\n';
    int lenu = 1, lenv = nlen - 2;
    // cout << lenv << '\n';
    int ma = 0;
    id = fa[u];
    int m = 0;
    for (int i=1; lenv; i++, id = fa[id]) {
        // ma = max(ma, lenu + len[id]);
        lu[i] = lenu + len[id];
        lv[i] = lenv + len[id];
        ma = max(ma, lv[i]);
        m = i;
        lenu ++;   lenv --;
    }
    vector<int> flu(lu), flv(lv);
    for (int i=2; i<=m; i++) {
        flu[i] = max(flu[i-1], flu[i]);
    }
    bool bo2 = (len[u] >= len[1]);
    for (int i=1; i<=m && !bo2; i++) {
        if (flu[i] >= len[1]) {
            bo2 = true;
        }
    }
    bool bo1 = true;
    for (int i=m; i>m / 2 && bo1; i--) {
        if (lv[i] > flu[i - 1]) {
            bo1 = false;
        }
    }
    if (bo1 ) {
        flu = lu;
        for (int i=1; i<m / 2; i++) {
            flu[i] = max(flu[i], flu[i + 1]);
        }
        for (int i=m / 2 + 1; i<=m; i++) {
            flv[i+1] = max(flv[i], flv[i + 1]);
        }
        for (int i=1; i<m/2; i++) {
            if (flu[i + 1] < flv[m - i]) {
                
            }
        }
    }
    if (!bo1 ) {
        bo1 = (len[u] >= ma);
    }
    if (bo1 && bo2) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
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
    // scanf("%d",&T);
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
