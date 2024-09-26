#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL n, m, k;
    cin >> n >> m >> k;
    vector<array<LL, 2> > a(n+10);
    for (int i=1; i<=n; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][1] = min(a[i][1], m * k);
    }
    LL num = 0, ans = 0, id = -1;
    for (int i=1; i<=n; i++) {
        LL d = a[i][1] / m;
        ans += d;
        a[i][1] %= m;
        int now = a[i][0] + d;
        while (id != -1 && now > a[id][0] + k) {
            num -= a[id][1];
            if (num <= 0) {
                id = i;  num = 0;
                break;
            }
            id ++;
        }
        num += a[i][1];
        while (num >= k) {
            
        }
        if (num >= k) {
            num -= k;
            ans ++;
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
    // scanf("%d",&T);
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
