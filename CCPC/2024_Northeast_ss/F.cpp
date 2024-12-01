#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
// using i128 = __int128;

void work() {
    LL p, x, k;
    cin >> p >> x >> k;
    vector<LL> fk;
    for (int i=2; i*i <= k; i++) {
        if (k % i == 0) {
            fk.push_back(i);
            while (k % i == 0)  k /= i;
        }
    }
    if (k != 1) {
        fk.push_back(k);
    }
    for (auto &fki : fk) {
        while (p % fki == 0)  p /= fki;
    }
    LL ans = 0;
    vector<LL> nk;
    priority_queue<LL, vector<LL>, greater<> > pri;
    pri.push(1);
    map<LL, int> mp;
    mp[1] = 1;
    while (!pri.empty() ) {
        LL t = pri.top();  pri.pop();
        // i128 lt = t;
        nk.push_back(t);
        // if (nk.size() >= 10) {
        //     cout << "****\n";
        //     return;
        // }
        for (auto &fki : fk) {
            if (fki > x)  continue;
            if (t > x / fki)  continue;
            if (mp[t * fki] )  continue;
            mp[t * fki] = 1;
            pri.push(t * fki);
            // if (pri.size() >= 10) {
            //     cout << "**\n";
            //     return;
            // }
        }
    }
    // cout << nk.size() << '\n';
    // return;
    // for (auto &kkk : nk) {
    //     cout << kkk << '\n';
    // }
    for (LL i = 1; i*i <= p; i++) {
        if (i > x)  break;
        if (p % i)  continue;
        LL fx = x / i;
        int l = 0, r = nk.size() - 1;
        while (l < r) {
            int mid = ((l + r + 1) >> 1);
            if (nk[mid] <= fx)  l = mid;
            else r = mid - 1;
        }
        ans += l + 1;
        // cout << i << ' ' << l + 1 << '\n';
        if (i * i == p)  break;
        LL fi = p / i;
        if (fi > x)  continue;
        fx = x / fi;
        l = 0;  r = nk.size() - 1;
        while (l < r) {
            int mid = ((l + r + 1) >> 1);
            if (nk[mid] <= fx)  l = mid;
            else r = mid - 1;
        }
        ans += l + 1;
        // cout << fi << ' ' << l + 1 << '\n';
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
