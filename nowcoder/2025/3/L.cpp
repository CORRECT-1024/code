#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    n ++;
    vector<int> ans;
    vector<vector<int> > a(n+10, vector<int> (n+10));
    int fnum = 1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            a[i][j] = fnum;
            fnum ++;
        }
    }
    ans.push_back(1);
    for (int i=1; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            ans.push_back(a[j][i]);
        }
        for (int j=n; j>i; j--) {
            ans.push_back(a[j][i]);
            ans.push_back(a[j][i+1]);
        }
    }
    for (int i=n-1; i>=1; i--) {
        ans.push_back(a[i][i]);
    }
    cout << "Yes\n";
    for (auto &x : ans) {
        cout << x << ' ';
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
    // cin >> T;
    while(T--) {
        work();
    }

   return 0;
}
