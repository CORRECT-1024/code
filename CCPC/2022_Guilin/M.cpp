#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N = 3e5;
int xds[N * 4];

void build(int k, int l, int r) {
    if (l == r) {
        xds[k] = 0;  return;
    }
    int mid = ((l + r) >> 1);
    build(2*k, l, mid);  build(2*k+1, mid+1, r);
    xds[k] = 0;
}
void add(int k, int l, int r, int id) {
    if (l == r) {
        if (l == id)  xds[k] = 1;
        return;
    }
    int mid = ((l + r) >> 1);
    if (id <= mid)  add(2*k, l, mid, id);
    else add(2*k+1, mid+1, r, id);
    xds[k] = xds[2*k] + xds[2*k+1];
}
int find(int k, int l, int r, int id) {
    if (l > id)  return xds[k];
    if (r <= id)  return 0;
    int mid = ((l + r) >> 1);
    int ans = 0;
    ans += find(2*k, l, mid, id);
    ans += find(2*k+1, mid+1, r, id);
    return ans;
}
void work() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    string s;  cin >> s;
    build(1, 1, n);
    LL sum = 0, fsum = (LL)n * (n - 1) / 2;
    for (int i=1; i<=n; i++) {
        sum += find(1, 1, n, a[i]);
        add(1, 1, n, a[i]);
    }
    cout << sum << '\n';
    sum %= 10;
    fsum %= 10;
    int id = 1;  // 1st id
    int p = 1; // 正 / 反
    for (auto &c : s) {
        if (c == 'S') {
            int d = (n - a[id]) - (a[id] - 1);
            d %= 10;   sum = sum + 10 + d;
            sum %= 10;
            id += p;
            if (id == n + 1)  id = 1;
            if (id == 0)  id = n;
        } else {
            sum = fsum + 10 - sum;
            sum %= 10;
            p *= -1;
            id += p;
            if (id == n + 1)  id = 1;
            if (id == 0)  id = n;
        }
        cout << (char)('0' + sum);
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
    // cin >> T;
    while(T--) {
        work();
    }

   return 0;
}
