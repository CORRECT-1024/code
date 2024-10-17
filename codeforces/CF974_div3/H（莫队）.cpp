//区间内必须每个数都有偶数个
//一眼莫队板子题，不想写啊
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n+10, 0);
    int mx = 0;
    map<int, int> mp;
    int mpid = 1;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        // mx = max(mx, a[i]);
        if (mp[a[i]] == 0)  mp[a[i]] = mpid ++;
        a[i] = mp[a[i]];
    }
    mx = mpid;
    vector<array<int, 4> > qu(q+10, {0});
    int len = sqrt(n);
    int num = (n - 1) / len + 1;
    for (int i=1; i<=q; i++) {
        cin >> qu[i][0] >> qu[i][1];
        qu[i][2] = i;
        qu[i][3] = (qu[i][0] - 1) / len + 1;
    }
    sort(&qu[1], &qu[q+1], [&](array<int, 4>&x, array<int, 4>&y) {
        if (x[3] == y[3]) return x[1] < y[1];
        return x[3] < y[3];
    });
    int l = 1, r = 1;
    vector<int> bo(mx+10, 0), ans(q+10, 0);
    int fbo = 0;
    for (int i=1; i<=q; i++) {
        if (qu[i][3] != qu[i-1][3]) {
            r = 0;  l = 1;
            // bo = vector<int> (mx + 10, 0);
            for (int j=0; j<=mx; j++) bo[j] = 0;
            fbo = 0;
        }
        while (r < qu[i][1]) {
            r ++;
            bo[a[r]] ^= 1;
            if (bo[a[r]] ) fbo ++;
            else fbo --;
        }
        while (l != qu[i][0]) {
            if (l < qu[i][0]) {
                bo[a[l]] ^= 1;
                if (bo[a[l]] ) fbo ++;
                else fbo --;
                l ++;
            } else {
                l --;
                bo[a[l]] ^= 1;
                if (bo[a[l]] ) fbo ++;
                else fbo --;
            }
        }
        if (fbo == 0) {
            ans[qu[i][2]] = 1;
        }
    }
    for (int i=1; i<=q; i++) {
        if (ans[i]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
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
