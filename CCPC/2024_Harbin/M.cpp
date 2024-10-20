#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

vector<LL > ans;

void dfs(LL x, int id, vector<array<LL, 2> > &a) {
    if (id == a.size()) {
        ans.push_back(x);
        return;
    }
    for (int i=0; i<=a[id][1]; i++) {
        dfs(x, id + 1, a);
        x *= a[id][0];
    }
}
void work() {
    LL n;
    cin >> n;
    ans = vector<LL >();
    vector<array<LL, 2> > a;
    LL m = n;
    for (int i=2; i*i <= n && i <= m; i++) {
        int num = 0;
        while (m % i == 0) {
            num ++;
            m /= i;
        }
        if (num) a.push_back({i, num});
    }
    if (m > 1)  a.push_back({m, 1});
    dfs((LL)1, 0, a);
    sort(ans.begin(), ans.end());
    ans.push_back(n+1);
    LL fans = 0, la = 1, num = n;
    for (int i=0; i<ans.size(); i++) {
        fans += (ans[i] - la) * num;
        la = ans[i];
        num = n / ans[i];
    }
    cout << fans << '\n';
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