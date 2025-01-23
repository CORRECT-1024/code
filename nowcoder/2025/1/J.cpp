#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N = 2e5 + 10;

void work() {
    int n;
    cin >> n;
    vector<int> a(n+10, 0), b(N, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        b[a[i]] ++;
    }
    LL ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j * j <= a[i]; j++) {
            if (a[i] % j)  continue;
//             if (__gcd(a[i], a[i] ^ j) == j) ans += b[a[i] ^ j];
            if ((a[i] | j) == a[i]) ans += b[a[i] ^ j];
            if (j * j == a[i])  continue;
            int k = a[i] / j;
//             if (__gcd(a[i], a[i] ^ k) == k) ans += b[a[i] ^ k];
            if ((a[i] | k) == a[i]) ans += b[a[i] ^ k];
        }
    }
//     ans /= 2;
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
