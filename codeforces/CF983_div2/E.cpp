// n为奇数时, 结论有错
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<int> a(n+10, 0), d2(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    for (int i=1; i<=n; i++) {
        d2[i] = a[i] - a[(i + n - 2 - 1) % n + 1];
        cout << d2[i] << ' ';
    }
    bool bo = true;
    for (int i=1; i<=n; i++) {
        if (d2[i] & 1) {
            cout << -1 << '\n';
            return;
        }
    }
    vector<int> ans(n+10, 0);
    LL sum1 = 0;
    for (int i=1; i<=n; i+=2) {
        sum1 += d2[i];
        int fd = d2[i] / 2;
        ans[i] = fd;
        d2[i] = 0;  d2[(i + 2 - 1) % n + 1] -= 2 * fd;
    }
    if (sum1 != 0) {
        cout << -1 << '\n';
        return;
    }
    sum1 = 0;
    for (int i=2; i<=n; i+=2) {
        sum1 += d2[i];
        int fd = d2[i] / 2;
        ans[i] = fd;
        d2[i] = 0;  d2[(i + 2 - 1) % n + 1] -= 2 * fd;
    }
    if (sum1 != 0) {
        cout << -1 << '\n';
        return;
    }
    a[1] += 2 * ans[1] + ans[n] + ans[2];
    a[2] += 2 * ans[2] + ans[1] + ans[2 % n + 1];
    if (a[1] > a[2]) {
        LL fd = a[1] - a[2];
        for (int i=2; i<=n; i+=2) {
            ans[i] += fd;
        }
    } else if (a[1] < a[2]) {
        LL fd = a[2] - a[1];
        for (int i=1; i<=n; i+=2) {
            ans[i] += fd;
        }
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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
    while(T--){
        work();
    }

   return 0;
}
