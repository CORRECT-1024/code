#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        int x;  cin >> x;
        a[x] ++;
    }
    int ma = -1;
    for (int i=1; i<=n; i++) {
        ma = max(ma, a[i]);
    }
    sort(&a[1], &a[n+1], [&](int x, int y) {return x > y;});
    int id = 0, sum = 0;
    // for (int i=k; i>=1; i--) {
    //     while (a[id + 1] > i) {
    //         id ++;  sum += a[id];
    //     }
    //     if (sum - (i - 1) * id <= k - i) {
    //         cout << "pigstd\n";
    //         return;
    //     }
    // }
    // vector<int> b(n+10, 0);
    // for (int i=1; i<=n; i++) {
    //     b[a[i]] ++;
    // }
    // for (int i=n-1; i>=1; i--) {
    //     b[i] += b[i+1];
    // }
    int ans = 0; sum = 0;
    int p = a[1]; id = 0;
    for (int i=1; i<=n+1; i++) {
        if (a[i] + k >= p && sum - id * p <= k) {
            if (a[i] == 0) {
                cout << "pigstd\n";  return;
            }
            ans ++;  continue;
        }
        while (a[i] + k < p) {
            p --;
            while (id < n && a[id + 1] > p) {
                id ++;
                sum += a[id];
            }
        }
        if (sum - id * p <= k) {
            if (a[i] == 0) {
                cout << "pigstd\n";  return;
            }
            ans ++;
        } else {
            break;
        }
    }
    cout << ans << '\n';
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
