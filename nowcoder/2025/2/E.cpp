#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N = 2e5 + 10;
const LL FNUM = -1e16;
LL xds[4 * N];

void build(int k, int l, int r, vector<LL> &c) {
    if (l == r) {
        xds[k] = c[l];  return;
    }
    int mid = ((l + r) >> 1);
    build(2*k, l, mid, c);
    build(2*k+1, mid + 1, r, c);
    xds[k] = max(xds[2*k], xds[2*k+1]);
}
LL find(int k, int l, int r, int al, int ar) {
    if (l >= al && r <= ar)  return xds[k];
    if (l > ar || r < al)  return FNUM;
    int mid = ((l + r) >> 1);
    LL ans = FNUM;
    ans = find(2*k, l, mid, al, ar);
    ans = max(ans, find(2*k+1, mid+1, r, al, ar));
    return ans;
}
void work() {
    int n, q;
    cin >> n >> q;
    vector<LL> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    vector<LL> b(n+10, 0), c(b);
    for (int i=1; i<=n; i++) {
        b[i] = b[i-1] + a[i];
    }
    for (int i=1; i<=n; i++) {
        c[i] = a[i] - b[i-1];
    }
    build(1, 1, n, c);
    while (q --) {
        LL l, r; 
        cin >> l >> r;
        if (l == r) {
            cout << 0 << '\n';
            continue;
        }
        LL fans = find(1, 1, n, l + 1, r) + b[l - 1];
        fans = max(fans, (LL)0);
        cout << fans << '\n';
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
    while(T--) {
        work();
    }

   return 0;
}
