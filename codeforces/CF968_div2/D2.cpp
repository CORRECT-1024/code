//建成图, 算初始答案, 对每个点存最大的两个出路
//每条边维护权值(重边数+1), ans=max(某边权值-1的答案,初始答案)
//明天再写
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

// bool cmp(array<int, 2>&x, array<int, 2>&y) {
//     return x[1] > y[1];
// }
void work() {
    LL n, m;
    cin >> n >> m;
    LL mau = 0, mav = 0;
    vector<array<int, 2> > to(n+10);
    for (int i=1; i<=n; i++) {
        int l;  cin >> l;
        vector<LL> a(l+10, 0);
        for (int i=1; i<=l; i++) {
            cin >> a[i];
        }
        sort(&a[1], &a[l+1]);
        LL u = -1, v = -1;
        int k = 0;
        for (int i=1; i<=l; i++) {
            if (a[i] < k)  continue;
            if (a[i] == k) {
                k ++;  continue;
            }
            while (a[i] > k) {
                if (u == -1)  u = k;
                else {
                    v = k;  break;
                }
                k ++;
            }
            if (a[i] == k) {
                k ++;  continue;
            }
        }
        if (u == -1) {
            u = k;  v = k + 1;
        } else if (v == -1) {
            v = k;
        }
        to[i][0] = u;  to[i][1] = v;
        // cout << u << ' ' << v << '\n';
        mau = max(mau, u);
        mav = max(mav, v);
    }
    // sort(&to[1], &to[n + 1], cmp);
    sort(&to[1], &to[n + 1], [&](array<int, 2>&x, array<int, 2>&y) {
        return x[1] > y[1];
    });
    vector<LL> b(mav + 10, 0), du(mav + 10, 0);
    for (int i=0; i<=mav; i++) {
        b[i] = i;
    }
    int id = 1;
    LL ans = 0;
    if (m > mav) ans = (m + mav + 1) * (m - mav) / 2;
    // cout << ans << '\n';
    for (int i=mav; i>=0; i--) {
        while (id <= n && i == to[id][1] ) {
            // cout << to[id][0] << ' ' << to[id][1] << '\n';
            du[to[id][0]] ++;
            b[to[id][0]] = max(b[to[id][0]], b[i]);
            id ++;
        }
        b[i] = max(b[i], mau);
        if (i <= m) ans += b[i];
        // cout << b[i] << '\n';
    }
    vector<LL> c(b), sum(b);
    int fm = min(mav, m);
    sort(&c[0], &c[fm + 1]);
    sum[0] = c[0];
    for (int i=1; i<=fm; i++) {
        sum[i] = sum[i-1] + c[i];
    }
    for (int i=0; i<=mav; i++) {
        if (du[i] <= 1)  continue;
        int l = 0, r = fm;
        while (l < r) {
            int mid = ((l + r + 1) >> 1);
            if (c[mid] < b[i]) l = mid;
            else r = mid - 1;
        }
        if (c[l] >= b[i])  continue;
        LL num = b[i] * (l + 1) + sum[fm] - sum[l];
        if (m > mav) {
            num += (m + mav + 1) * (m - mav) / 2;
        }
        ans = max(ans, num);
        // cout << num << '\n';
        // LL num = min(b[i], m);
        // num = b[i] * (num + 1);
        // if (m > b[i]) {
        //     num += (m + b[i] + 1) * (m - b[i]) / 2;
        // }
        // ans = max(ans, num);
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
