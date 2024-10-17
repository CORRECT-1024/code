#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, q;
    cin >> n >> q;
    vector<LL> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    vector<array<LL, 2> > b;
    b.push_back({(LL)0, (LL)0});
    map<LL, int> mp;
    for (LL i=2; i<=n; i++) {
        LL num = (i - 1) * (n - i + 1);
        // cout << num << ' ';
        mp[num] += a[i] - a[i-1] - 1;
        mp[num + b[b.size()-1][1] - (i - 2) * (n - i + 1)] ++;
        b.push_back({a[i-1], num});
    }
    // cout << '\n';
    mp[b[b.size()-1][1]] ++;
    b.push_back({a[n], (LL)0});
    while (q --) {
        LL x;  cin >> x;
        cout << mp[x] << ' ';
        // int l = 0, r = b.size() - 1;
        // while (l < r) {
        //     int mid = ((l + r - 1) >> 1);
        //     if (b[mid][0] <= x) r = mid;
        //     else l = mid + 1;
        // }
        // LL ans = b[l][1];
        // if (x == b[l][0]) ans += b[l-1][1];
        // cout << ans << ' ';
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
    // scanf("%d",&T);
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
