#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, k;
    cin >> n >> k;
    vector<LL> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    sort(&a[1], &a[n+1], [&](LL &x, LL &y) {
        return x < y;
    });
    vector<array<LL, 2> > b(k+10);
    for (int i=1; i<=k; i++) {
        cin >> b[i][0] >> b[i][1];
    }
    sort(&b[1], &b[k+1], [&](array<LL, 2>&x, array<LL, 2>&y) {
        return x[0] < y[0];
    });
    b[k+1][0] = 1e9+10;  b[k+1][1] = 1e9+10;
    LL ans = 0;
    LL last = -1;
    int id = 1;
    int i;
    for ( i=1; i<=k+1; i++) {
        if (b[i][0] > last + 1) {
            int fid = i;
            while (fid < k+1 && b[fid][1] > 0) {
                fid ++;
            }
            while (id <= n && a[id] < b[fid][0]) {
                ans += a[id] - (last + 1);
                id ++;
            }
            if (id == n + 1) {
                break;
            }
            i = fid;
            last = b[fid][0];
        } else {
            int fid = i;
            while (fid < k + 1 && b[fid][1] > 0) {
                fid ++;
            }
            while (id <= n && b[i][1] -- && a[id] < b[fid][0]) {
                ans += a[id] - b[i][0];
                id ++;
            }
            if (id == n + 1) break;
            last = b[i][0];
        }
    }
    if (ans & 1) {
        cout << "Pico\n";
    } else {
        cout << "FuuFuu\n";
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
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
