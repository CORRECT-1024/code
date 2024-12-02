// 一开始想成莫队了，幸好中间发现不对了
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

const int N = 5e5;
int xds[N * 4];

void build(int k, int l, int r) {
    if (l == r) {
        xds[k] = -1;  return;
    }
    int mid = ((l + r) >> 1);
    build(2*k, l, mid);  build(2*k+1, mid+1, r);
    xds[k] = -1;
}
// int fun(int x, int y) P{
//     int ans = -1;
//     if (x != -1) ans = x;
//     if (y != -1) {
//         if (ans == -1)  ans = y;
//         else ans = min(ans, y);
//     }
//     return ans;
// }
void add(int k, int l, int r, int al, int ar) {
    if (r < ar || l > ar)  return;
    if (l == r) {
        if (l == ar) {
            xds[k] = al;
        }
        return;
    }
    int mid = ((l + r) >> 1);
    if (ar <= mid)  add(2*k, l, mid, al, ar);
    else  add(2*k+1, mid+1, r, al, ar);
    xds[k] = max(xds[2*k], xds[2*k+1]);
}
int findr(int k, int l, int r, int ar) {
    if (xds[k] == -1)  return -1;
    if (r < ar)  return -1;
    int ans = -1;
    if (l == r) {
        if (xds[k] == -1)  return -1;
        return l;
    }
    int mid = ((l + r) >> 1);
    if (mid >= ar && xds[2*k] != -1)  ans = findr(2*k, l, mid, ar);
    if (ans == -1)  ans = findr(2*k+1, mid+1, r, ar);
    return ans;
}
int findl(int k, int l, int r, int al, int ar) {
    if (xds[k] == -1)  return -1;
    if (r < ar)  return -1;
    if (l >= ar) {
        return xds[k];
    }
    int ans = -1;
    int mid = ((l + r) >> 1);
    if (mid >= ar)  ans = findl(2*k, l, mid, al, ar);
    ans = max(ans, findl(2*k+1, mid+1, r, al, ar));
    return ans;
}

void work() {
    int n;
    cin >> n;
    vector<array<int, 3> > a(n+10);
    vector<array<int, 2> > b(n+10);
    for (int i=1; i<=n; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
        b[i][0] = -1;  b[i][1] = 1e9 + 1;
    }
    sort(&a[1], &a[n+1], [&](array<int, 3> &x, array<int, 3> &y) {
        if (x[0] == y[0])  return x[1] > y[1];
        return x[0] < y[0];
    });
    map<int, int> to;
    for (int i=1; i<=n; i++) {
        to[a[i][0]] = 1; to[a[i][1]] = 1;
    }
    map<int, int> fto;
    int toid = 1;
    for (auto &[num, p] : to) {
        p = toid;
        fto[toid] = num;
        toid ++;
    }
    for (int i=1; i<=n; i++) {
        a[i][0] = to[a[i][0]];
        a[i][1] = to[a[i][1]];
    }
    vector<int> ans(n+10, 0);
    build(1, 1, toid);
    for (int i=1; i<=n; i++) {
        int r = findr(1, 1, toid, a[i][1]);  // (xds里所有的) r >= a[i][1] 里 min_r
        b[a[i][2]][1] = r;
        int l = findl(1, 1, toid, a[i][0], a[i][1]);  // r >= a[i][1] 里 max_l
        b[a[i][2]][0] = l;
        add(1, 1, toid, a[i][0], a[i][1]);
        if (l == -1)  continue;
        ans[a[i][2]] = fto[r] - fto[l] + 1;
        ans[a[i][2]] -= fto[a[i][1]] - fto[a[i][0]] + 1;
        if (ans[a[i][2]] == 0 && (i == n || a[i][0] != a[i+1][0] || a[i][1] != a[i+1][1]) ) {
            int id = i-1;
            while (id && a[id][0] == a[i][0] && a[id][1] == a[i][1]) {
                ans[a[id][2]] = 0;  id --;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i] << '\n';
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
    cin >> T;
    while(T--) {
        work();
    }

   return 0;
}
