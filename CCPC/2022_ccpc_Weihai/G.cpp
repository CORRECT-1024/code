#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL x, n;
    cin >> x >> n;
    LL y = 1;
    while (y <= x) {
        y <<= 1;
    }
    if (x == 1) {
        while (n --) {
            LL l, r;
            cin >> l >> r;
            cout << r - l + 1 << '\n';
        }
        return;
    }
    if (x % 2 == 0) {
        while (n --) {
            LL l, r;  cin >> l >> r;
            cout << 0 << '\n';
        }
        return;
    }
    vector<int> bo(y+10, 0);
    for (int i=1; i<=y; i++) {
        LL p = i * x % y;
        p &= x;
        if (__gcd(p, x) == 1) {
            bo[i] = 1;
        }
        bo[i] += bo[i-1];
        // cout << bo[i] << ' ';
    }
    // cout << '\n';
    // cout << bo[y] << '\n';
    while (n --) {
        LL l, r;
        cin >> l >> r;
        l --;
        LL ansr = bo[y] * (r / y) + bo[r % y];
        LL ansl = bo[y] * (l / y) + bo[l % y];
        LL ans = ansr - ansl;
        cout << ans << '\n';
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
    // scanf("%d",&T);
    // cin >> T;
    while(T--){
        work();
    }

   return 0;
}
