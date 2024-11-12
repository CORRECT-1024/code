#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<vector<int> > a(5, vector<int>(n+10, 0));
    for (int i=1; i<=3; i++) {
        for (int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> bo(n+10, 0);
    bo[1] = 1;
    // vector<int> id(5, 1);
    vector<array<int, 2> > f(n+10, {0, 0}), ma(5, {0, 0});
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=3; j++) {
            if (bo[i] )  ma[j] = max(ma[j], {a[j][i], i});
            if (! bo[i + 1] && ma[j][0] > a[j][i + 1]) {
                f[i + 1] = {j, ma[j][1]};
                bo[i + 1] = 1;
            }
        }
    }
    if (! bo[n] ) {
        cout << "NO\n";   return;
    }
    vector<array<int, 2> > ans;
    int x = n;
    while (x != 1) {
        ans.push_back({f[x][0], x});
        x = f[x][1];
    }
    cout << "YES\n";
    cout << ans.size() << '\n';
    for (int i=ans.size()-1; i>=0; i--) {
        char c = ' ' ;
        if (ans[i][0] == 1) c = 'q';
        else if (ans[i][0] == 2) c = 'k';
        else c = 'j';
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
