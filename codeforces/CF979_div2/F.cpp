// 之前结论没想对，甚至样例跑的都不对，但没看出来
// 改一下xds维护的值就对了
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N = 2e5 + 10;

int xds[N * 4], lj[N * 4];

void build(int k, int l, int r) {
    if (l == r) {
        lj[k] = 0;
        xds[k] = 0;  return;
    }
    int mid = ((l + r ) >> 1);
    build(2*k, l, mid);  build(2*k+1, mid + 1, r);
    xds[k] = 0;  lj[k] = 0;
}
void push(int k, int l, int r) {
    xds[k] = max(lj[k], xds[k]);  
    if (l != r) {
        lj[2*k] = max(lj[2*k], lj[k]);  lj[2*k+1] = max(lj[2*k+1], lj[k]);
    }
    lj[k] = 0;
}
int find(int k, int l, int r, int id) {
    if (lj[k] ) {
        push(k, l, r);
    }
    if (l == r) {
        return xds[k];
    }
    int mid = ((l + r ) >> 1);
    if (id <= mid) return find(2*k, l, mid, id);
    return find(2*k+1, mid+1, r, id);
}
void fun(int k, int l, int r, int al, int ar, int val) {
    if (al > ar)  return;
    if (lj[k] ) {
        push(k, l, r);
    }
    if (l >= al && r <= ar) {
        lj[k] = val;  return;
    }
    int mid = ((l + r ) >> 1);
    if (al <= mid) fun(2*k, l, mid, al, ar, val);
    if (ar > mid)  fun(2*k+1, mid+1, r, al, ar, val);
}
void work() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    vector<int> ans(n+10, 0), fir(n+10, -1), las(n+10, -1);
    vector<vector<int> > id(n+10, vector<int>());
    int l = 1;
    // stack<int> st;
    // map<int, int> sthas;
    for (int i=1; i<=n; i++) {
        if (fir[a[i]] != -1 && fir[a[i]] <= las[a[i]]) {
            int fid = find(1, 1, n, id[a[i]][fir[a[i]]]);
            // cout << i << ' ' << id[a[i]][fir[a[i]]] << ": " << fid << '\n';
            // if (fid != a[i]) {
            // while (fir[fid] <= las[fid] && id[fid][fir[fid]] < id[a[i]][las[a[i]]]) {
            while ( l <= fid ) {
                ans[l] = i - 1;
                // cout << l << ' ' << i-1 << '\n';
                fir[a[l]] ++;  l ++;
            }
            // }
        }
        id[a[i]].push_back(i);
        if (fir[a[i]] == -1) fir[a[i]] = 0;
        if (las[a[i]] != -1)  fun(1, 1, n, id[a[i]][las[a[i]]] + 1, i - 1, id[a[i]][las[a[i]]]);
        las[a[i]] ++;
        // cout << "fun " << id[a[i]][fir[a[i]]] << ' ' << i << ' ' << a[i] << '\n';
    }
    while (l <= n) {
        ans[l] = n;
        l ++;
    }
    while (m --) {
        int l, r;   cin >> l >> r;
        if (ans[l] >= r) {
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
    cin >> T;
    while(T--) {
        work();
    }

   return 0;
}
