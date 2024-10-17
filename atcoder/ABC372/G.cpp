#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<LL> a(n+10, 0), b(n+10, 0), c(n+10, 0);
    LL ans = 0, x = 1e9, y = 1e9;
    LL d = 1;
    for (int i=1; i<=n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        d = max(d, (a[i] + b[i] - 1) / b[i]);
        c[i] --;
        y = min(y, (c[i] - a[i]) / b[i]);
    }
    for (int i=1; i<=n; i++) {
        x = min(x, (c[i] - y * b[i]) / a[i]);
    }
    ans = y * x;
    // cout << y << '\n';
    // return;
    bool bo = true;
    while (x > 0 && (bo || y > 1) ) {
        if (!bo) {
            y --;
        } else {
            bo = false;
        }
        LL nx = 1e9;
        for (int i=1; i<=n; i++) {
            nx = min(nx, (c[i] - y * b[i]) / a[i]);
        }
        if (nx == 0) break;
        if (nx == x) {
            continue;
        }
        ans += (nx - x) * y;
        // x = nx;
        LL ny = 1e9;
        for (int i=1; i<=n; i++) {
            ny = min(ny, (c[i] - nx * a[i]) / b[i]);
        }
        y = ny;  x = nx;
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
    // scanf("%d",&T);
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
