#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<LL> a(n+10, 0), sum(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    vector<LL> bi(n+10, 0), bsum(n+10, 0);
    for (int i=1; i<=n; i++) {
        bi[1] += sum[i];
    }
    bsum[1] = bi[1];
    LL num = n;
    for (int i=2; i<=n; i++) {
        bi[i] = bi[i-1] - num * a[i-1];
        num --;
        bsum[i] = bsum[i-1] + bi[i];
        // cout << bi[i] << ' ' << bsum[i] << '\n';
    }
    // return;
    vector<LL> bid(n+10, 0);
    bid[1] = 1;  num = n;
    for (int i=2; i<=n; i++) {
        bid[i] = bid[i-1] + num;
        num --;
    }
    int q;  cin >> q;
    while (q --) {
        LL bl, br;
        cin >> bl >> br;
        bl --;
        LL ans = 0;
        int l = 1, r = n;
        while (l < r) {
            int mid = ((l + r + 1) >> 1);
            if (bid[mid] <= br) l = mid;
            else r = mid - 1;
        }
        ans += bsum[l-1];
        int rid = br - bid[l];
        ans += bi[l];
        ans -= bi[l + rid + 1] + (sum[l + rid] - sum[l-1]) * (n - l - rid);
        LL fans = 0;
        if (bl == 0) {
            cout << ans << '\n';
            continue;
        }
        l = 1; r = n;
        while (l < r) {
            int mid = ((l + r + 1) >> 1);
            if (bid[mid] <= bl) l = mid;
            else r = mid - 1;
        }
        fans += bsum[l-1];
        rid = bl - bid[l];
        fans += bi[l];
        fans -= bi[l + rid + 1] + (sum[l + rid] - sum[l-1]) * (n - l - rid);
        // cout << fans << ' ' << ans << '\n';
        cout << ans - fans << '\n';
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
    while(T--){
        work();
    }

   return 0;
}
