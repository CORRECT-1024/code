//sad，看错题了导致我敲了一遍线段树板子qvq
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

// const int N = 1e5 + 10;
// int xds[N * 4], sp[N * 4];

// void build(int k, int l, int r, vector<int> &a) {
//     if (l == r) {
//         xds[k] = a[l];  return;
//     }
//     int mid = ((l + r ) >> 1);
//     build(2*k, l, mid, a);
//     build(2*k+1, mid + 1, r, a);
//     xds[k] = max(xds[2*k], xds[2*k+1]);
// }
// void updete(int k, int l, int r, int al, int ar, int val) {
//     if (l > ar || r < al)  return;
//     if (l >= al && r <= ar) {
//         xds[k] += val;  sp[k] += val;
//         return;
//     }
//     int mid = ((l + r) >> 1);
//     if (al <= mid) updete(2*k, l, mid, al, ar, val);
//     if (ar > mid)  updete(2*k+1, mid+1, r, al, ar, val);
//     xds[k] = max(xds[2*k], xds[2*k+1]);
// }
// int check(int k, int l, int r, int al, int ar) {
//     if (l > ar || r < al)  return -1e9;
//     if (l >= al && r <= ar)  return xds[k];
//     int mid = ((l + r) >> 1);
//     int ans = max(check(2*k, l, mid, al, ar), check(2*k+1, mid+1, r, al, ar));
//     return ans;
// }
void work() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n+10, 0);
    int ans = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        ans = max(ans, a[i]);
    }
    while (m --) {
        string s;  int l, r;
        cin >> s >> l >> r;
        if (ans >= l && ans <= r) {
            if (s == "+") ans ++;
            else ans --;
        } 
        cout << ans << ' ' ;
    }
    cout << '\n';
    // build(1, 1, n, a);
    // while (m --) {
    //     string s;  int l, r;
    //     cin >> s >> l >> r;
    //     l = max(1, l);  r = min(n, r);
    //     int val = s == "+" ? 1 : -1;
    //     updete(1, 1, n, l, r, val);
    //     cout << xds[1] << ' ';
    // }
    // cout << '\n';
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
