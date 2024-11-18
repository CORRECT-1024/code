// 从11点到12点半，就写了这一道题
// 好在没看题解，自己想的。虽然感觉复杂了一点，好歹一发过了
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<LL> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    vector<LL> jian(n+10, 0), d(n+10, 0);
    for (int i=1; i<=n; i++) {
        d[i] = a[i] - a[(i + n - 2) % n + 1];
    }
    vector<LL> fd(n+10, 0);
    for (int i=1; i<=(n+1)/2; i++) {
        fd[i] = d[2*i-1];
        // cout << 2 * i - 1 << ' ';
    }
    for (int i=0; i<n/2; i++) {
        fd[(n+1)/2+i+1] = d[2 * (i + 1)];
        // cout << 2 * (i + 1) << ' ';
    }
    // cout << '\n';
    vector<LL> hsum(n+10, 0);
    LL ma = 0, id = -1;
    for (int i=n; i>=1; i--) {
        hsum[i] = hsum[i+1] + fd[i];
        if (hsum[i] >= ma) {
            ma = hsum[i];  id = i;
        }
    }
    for (int j=0; j<n; j++) {
        int fid = (id + j + n - 1) % n + 1;
        jian[fid] = fd[fid];
        fd[(fid + n) % n + 1] += fd[fid]; 
        fd[fid] = 0;
    }
    vector<LL> fans(n+10, 0);
    for (int i=1; i<=n; i++) {
        if (i & 1) {
            fans[i] = jian[i / 2 + 1];
        } else {
            fans[i] = jian[n / 2 + 1 + i / 2];
        }
    }
    vector<LL> qj(n+10, 0), qo(n+10, 0), hj(n+10, 0), ho(n+10, 0);
    for (int i=1; i<=n; i++) {
        if (i & 1) {
            qo[i-1] += fans[i];  hj[i+2] += fans[i];
        } else {
            qj[i-1] += fans[i];  ho[i+2] += fans[i];
        }
    }
    vector<LL> ans(n+10, 0);
    LL sumj = 0, sumo = 0;
    for (int i=1; i<=n; i++) {
        if (i & 1) {
            sumj += hj[i];  ans[i] += sumj;
        } else {
            sumo += ho[i];  ans[i] += sumo;
        }
    }
    sumj = 0;  sumo = 0;
    for (int i=n; i>=1; i--) {
        if (i & 1) {
            sumj += qj[i];  ans[i] += sumj;
        } else {
            sumo += qo[i];  ans[i] += sumo;
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
    while(T--) {
        work();
    }

   return 0;
}
