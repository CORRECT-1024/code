#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
//     vector<vector<int> > bian(n+10, vector<int> ());
    vector<int> du(n+10, 0);
    for (int i=1; i<n; i++) {
        int u, v;  cin >> u >> v;
        du[u] ++;  du[v] ++;
    }
    int ans1 = 0, ans2 = 0;
    for (int i=1; i<=n; i++) {
        if (du[i] == 1) {
            if (ans1 == 0)  ans1 = i;
            else if (ans2 != 0) {
                cout << "-1\n";  return;
            } else {
                ans2 = i;
            }
        }
    }
    cout << ans1 << ' ' << ans2 << '\n';
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
