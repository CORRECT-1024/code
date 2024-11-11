// 题目要求读漏了，直接改的话，边是n方
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<vector<array<int, 2> > > bian(n+10, vector<array<int, 2> >());
    for (int i=1; i<=3; i++) {
        vector<int> b(n+10, 0), c(n+10, 0);
        for (int i=1; i<=n; i++) {
            cin >> b[i];
            c[b[i]] = i;
        }
        for (int j=n; j>1; j--) {
            bian[c[j]].push_back({c[j - 1], i});
            // cout << i << ' ' << c[j] << "->" << c[j-1] << '\n';
        }
    }
    vector<array<int, 2> > f(n+10, {-1, -1});
    f[1] = {0, 0};
    queue<int> qu;
    qu.push(1);
    while (!qu.empty()) {
        int x = qu.front();  qu.pop();
        for (auto  &[to, id] : bian[x]) {
            if (f[to][0] != -1)  continue;
            qu.push(to);
            f[to] = {id, x};
        }
    }
    if (f[n][0] == -1) {
        cout << "NO\n";
        return;
    }
    vector<array<int, 2> > ans;
    int x = n;
    while (x != 1) {
        ans.push_back({f[x][0], x});
        x = f[x][1];
    }
    cout << ans.size() << '\n';
    for (int i=ans.size()-1; i>=0; i--) {
        char c = ' ';
        if (ans[i][0] == 1) {
            c = 'q';
        } else if (ans[i][0] == 2) {
            c = 'k';
        } else {
            c = 'j';
        }
        cout << c << ' ' << ans[i][1] << '\n';
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
    cin >> T;
    while(T--) {
        work();
    }

   return 0;
}
