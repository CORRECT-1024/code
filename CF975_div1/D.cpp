//预处理红色元素最小值为x时的贡献，枚举红色元素最小值
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<array<int, 2> > a(n+10);
    for (int i=1; i<=n; i++) {
        cin >> a[i][0];
        a[i][1] = i;
    }
    sort(&a[1],&a[n+1], [&](array<int, 2>&x, array<int, 2>&y) {
        return x[0] > y[0];
    });
    vector<int> con(n+10, 1), d(n+10, 0);
    con[a[1][1] - 1] = 0;
    con[a[1][1]] = 0;
    con[a[1][1] + 1] = 0;
    int mxnum = 0;
    vector<int> mxid;
    mxid.push_back(0);
    for (int i=1; i<=n; i++) {
        mxid.push_back(a[i][1]);
        if (a[i+1][0] != a[i][0])  break;
    }
    LL num = 0, ans = 0;
    vector<array<int, 3> > r(n+10, {0, 0, 0});
    for (int i=1; i<=n; i++) {
        r[i][0] = i;  r[i][1] = 0;  r[i][2] = i;
    }
    bool bo = true;
    for (int i=1; i<=n; i++) {
        int al = 0, ar = 0;
        if (i < mxid.size()) {
            d[mxid[i]] = 1;
            mxnum ++;
        }
        int id = a[i][1];
        if (r[id-1][1] && r[id + 1][1]) {
            al = r[id-1][0]; ar = r[id+1][2];
        } else if (r[id-1][1] ) {
            al = r[id-1][0]; ar = id;
        } else if (r[id + 1][1] ) {
            al = id;  ar = r[id + 1][2];
        } else {
            al = id;  ar = id;
        }
        int fnum = (ar - al) / 2 + 1;
        num += fnum - r[id-1][1] - r[id+1][1];
        r[al][1] = fnum;  r[al][2] = ar;
        r[ar][1] = fnum;  r[ar][0] = al;
        if (bo && ((ar - al + 1) & 1)) {
            int vl = 0, vr = mxid.size()-1;
            while (vl < vr) {
                int mid = ((vl + vr + 1) >> 1);
                if (mxid[mid] < al) vl = mid;
                else vr = mid - 1;
            }
            int mxl = vl + 1;
            vl = 0, vr = mxid.size()-1;
            while (vl < vr) {
                int mid = ((vl + vr + 1) >> 1);
                if (mxid[mid] < ar) vl = mid;
                else vr = mid - 1;
            }
            int mxr = vl;
            bool k = false;
            for (int i=mxl; i<=mxr; i++) {
                if ((mxid[i] - al) % 2 == 0) {
                    if (d[mxid[i]] == 0) mxnum ++;
                    d[mxid[i]] = 1;
                } else {
                    if (d[mxid[i]] == 1) mxnum --;
                    d[mxid[i]] = 0;
                }
                if (i != mxl) {
                    if ((mxid[i] - mxid[i-1]) & 1) {
                        bo = false;
                    }
                }
            }
        }
        int fd = mxnum == 0 ? -1 : 0;
        ans = max(ans, a[i][0] + num + fd);

        // cout << al << ' ' << ar << "*   ";
        // cout << a[i][0] << ' ' << num + fd << '\n'; 
        // ans = max(ans, a[i][0] + num);
    }
    ans += a[1][0];
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
