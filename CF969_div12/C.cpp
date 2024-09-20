// 得多练计数题啊，看了题解还是写的这么坎坷
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

const int N = 4e5;
int xds[N*4];

int gcd(int x, int y) {
    if (x == 0)  return y;
    if (y == 0)  return x;
    return __gcd(x, y);
}
void build(int k, int l, int r, vector<int>&b) {
    if (l == r) {
        xds[k] = b[l];   return;
    }
    int mid = ((l + r) >> 1);
    build(2*k, l, mid, b);
    build(2*k+1, mid+1, r, b);
    xds[k] = gcd(xds[2*k], xds[2*k+1]);
}
int check(int k, int l, int r, int al, int ar) {
    if (l > ar || r < al)  return 0;
    if (l >= al && r <= ar)  return xds[k];
    int mid = ((l + r) >> 1);
    int ans = 0;
    if (al <= mid)  ans = gcd(ans, check(2*k, l, mid, al, ar));
    if (ar > mid)  ans = gcd(ans, check(2*k+1, mid+1, r, al, ar));
    return ans;
}
bool fun(int x) {
    int k = 0;
    while (x) {
        k += (x & 1);
        x >>= 1;
    }
    return k <= 1;
}
void work() {
    int n;
    cin >> n;
    vector<LL> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    vector<LL> aa(n+10, 0), fid(n+10, 0);
    int id = 1;
    for (int i=1; i<=n; i++) {
        if (a[i] == a[i-1])  continue;
        aa[id] = a[i];  fid[id] = i;
        id ++;
        // cout << i << ' ';
    }
    int mn = n;
    n = id - 1;
    // for (int i=1; i<=n; i++) {
    //     cout << i << ' '  << fid[i] << '\n';
    // }
    // cout << '\n';
    swap(aa, a);
    vector<int> b(n+10, 0);
    for (int i=1; i<n; i++) {
        b[i] = a[i+1] - a[i];
        b[i] = abs(b[i]);
    }
    build(1, 1, n, b);
    int r = 2, p = 0;
    LL ans = 0;
    for (int i=1; i<n; i++) {
        // cout << i << '\n';
        if (r == i) r ++;
        p = check(1, 1, n, i, r - 1);
        while (r < n && ! fun(p) ) {
            p = gcd(p, b[r]);
            r ++;
        }
        if (r == n && !fun(p)) {
            break;
        }
        ans += (fid[i + 1] - fid[i]) * (mn - fid[r] + 1);
        // cout << fid[i] << ' ' << fid[i + 1] - fid[i] << "  " << fid[r] << ' ' << mn - fid[r] + 1 << '\n';
    }
    ans += mn;
    fid[n + 1] = mn + 1;
    for (int i=1; i<=n; i++) {
        LL d = fid[i+1] - fid[i];
        LL fans = d * (d - 1) / 2;
        ans += fans;
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
