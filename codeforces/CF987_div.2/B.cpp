#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<int> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    // bool ans = true;
    int id = 0, p = 0;
    while (++id <= n) {
        if (p ) {
            p = 0;  continue;
        }
        if (a[id] == id)  continue;
        if (a[id] == id + 1 && a[id+1] == id) {
            p = 1;  continue;
        }
        cout << "NO\n"; 
        return;
    }
    cout << "YES\n";
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
