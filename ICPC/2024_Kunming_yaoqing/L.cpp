// 想错了
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

vector<int> xds;

void build(int k, int l, int r, vector<int> &a) {
    if (k == 1) {
        xds = vector<int>(r * 4 + 10, 0);
    }
    if (l == r) {
        xds[k] = 0;  return;
    }
    int mid = ((l + r ) >> 1);
    build(2*k, l, mid, a);
    build(2*k+1, mid + 1, r, a);
    xds[k] = xds[2*k] + xds[2*k+1];
}
int find(int k, int l, int r, int en) {
    if (r <= en)  return xds[k];
    int mid = ((l + r ) >> 1);
    int ans = find(2*k, l, mid, en);
    if (en > mid) ans += find(2*k+1, mid+1, r, en);
    return ans;
}
void add(int k, int l, int r, int id, int d) {
    if (l == r) {
        if (l == id) {
            xds[k] += d;  a[l] += d;
        }
        return;
    }
    int mid = ((l + r ) >> 1);
    if (id > mid)  add(2*k+1, mid+1, r, id, d);
    else add(2*k, l, mid, id, d);
    xds[k] = xds[2*k] + xds[2*k+1];
}
void work() {
    LL n, p, q;
    cin >> n >> p >> q;
    p ++;  q ++;
    vector<array<int, 2> > u(n+10);
    for (int i=1; i<=n; i++) {
        cin >> u[i][0] >> u[i][1];
        u[i][0] ++;  u[i][1] ++;
    }
    sort(&u[1], &u[n+1]);

    LL ans = 0, sum = 0;
    for (int i=1; i<=p; i++) sum += i;
    for (int i=1; i<=q; i++) {
        ans += sum;
        sum += p;
    }
    ans -= p * q;

    int len = p + q - 1;
    vector<int> a(len+10, 0);
    build(1, 1, len, a);

    vector<LL> b(len+10, 0), hsum(len+10, 0);
    int qp = min(p, q);
    for (int i=1; i<=len; i++) {
        if (i <= qp) b[i] = i;
        else if ((len - i + 1) <= qp) b[i] = (len - i + 1);
        else b[i] = qp;
        cout << i << ": " << b[i] << '\n';
    }
    for (int i=len; i>=1; i--) {
        hsum[i] = hsum[i+1] + b[i];
    }

    int uid = 1;
    vector<int> c(n+10, 0);
    for (int i=2; i<=q; i++) {
        while (uid <= n && u[uid][0] == i - 1) {
            cout << u[uid][1] << '\n';
            cout << u[uid][1] + i - 2 << ": " << c[u[uid][1] + i - 2] << ' ' ;
            cout << u[uid][1] + i << ": " << find(1, 1, len, u[uid][1] + i) << '\n' ;
            // int d = 1 + find(1, 1, len, u[uid][1] + i - 2) - find(1, 1, len, u[uid][1] + i);
            int d = 1 + c[u[uid][1] + i - 2] - find(1, 1, len, u[uid][1] + i);
            if (d == 0) {
                uid ++;  continue;
            }
            add(1, 1, len, u[uid][1] + i, d);
            // ans -= d * hsum[u[uid][1] + i];
            uid ++;
        }
        c = vector<int>(n+10, 0);
        int fuid = uid;
        while (fuid <= n && u[fuid][0] == i) {
            c[u[fuid][1] + i - 1] = find(1, 1, len, u[fuid][1] + i - 1);
            fuid ++;
        }
    }
    for (int i=1; i<=len; i++) {
        
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
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
