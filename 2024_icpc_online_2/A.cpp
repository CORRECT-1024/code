#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct node {
    int id, num;
    string s;
};

bool cmp(node x, node y) {
    return x.num > y.num;
}
void work() {
    int n, m;
    cin >> n >> m;
    int c = 1e9;
    for (int i=1; i<=m; i++) {
        int fc;  cin >> fc;
        c = min(c, fc);
    }
    vector<node> a(n+10);
    map<string, int> mp;
    int id = 1;
    for (int i=1; i<=n; i++) {
        a[i].id = i;
        cin >> a[i].num >> a[i].s;
        if (mp[a[i].s] == 0) {
            mp[a[i].s] = id;
            id ++;
        }
    }
    sort(&a[1], &a[n+1], cmp);
    vector<int> b;
    vector<vector<int> > bo(id+10, vector<int>());
    for (int i=1; i<=n; i++) {
        int fid = mp[a[i].s];
        if (bo[fid].size() >= c)  continue;
        bo[fid].push_back(a[i].num);
        b.push_back(a[i].num);
    }
    vector<int> ans(n+10, 0);
    for (int i=1; i<=n; i++) {
        int l = 0, r = b.size()-1;
        int num = a[i].num, fid = mp[a[i].s];
        while (l < r) {
            int mid = ((l + r + 1) >> 1);
            if (b[mid] > num) l = mid;
            else r = mid - 1;
        }
        if (b[l] <= num) l --;
        int fans = l + 2;
        l = 0, r = bo[fid].size() - 1;
        while (l < r) {
            int mid = ((l + r + 1) >> 1);
            if (bo[fid][mid] > num) l = mid;
            else r = mid - 1;
        }
        if (bo[fid][l] <= num) l --;
        // fans -= l + 1;
        if (l == bo[fid].size() - 1)  fans --;
        ans[a[i].id] = fans;
        // cout << a[i].id << ' ' << fans << '\n';
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i] << '\n';
    }
}
int main()
{
    #ifdef QHK
    freopen("qi.in","r",stdin);
    freopen("qi.out","w",stdout);
    #endif
    ios::sync_with_stdio(false);  cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        work();
    }

    return 0;
}