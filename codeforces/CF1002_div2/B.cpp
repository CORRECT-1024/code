#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    int d = n - k;
    if (d == 0) {
        int ans = 1;
        for (int i=2; i<=n; i+=2) {
            if (a[i] == ans) ans ++;
            else break;
        }
        cout << ans << '\n';
    } else {
        bool bo = false;
        for (int i=2; i<=d + 2; i++) {
            if (a[i] != 1)  {
                bo = true;  break;
            }
        }
        if (bo) {
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
        }
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
