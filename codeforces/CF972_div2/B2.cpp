#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define QHK 1

void work() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(m+10, 0);
    for (int i=1; i<=m; i++) {
        cin >> a[i];
    }
    sort(&a[1], &a[m+1]);
    while (q --) {
        int x;  cin >> x;
        int l = 1, r = m;
        while (l < r) {
            int mid = ((l + r + 1) >> 1);
            if (a[mid] < x) l = mid;
            else r = mid - 1;
        }
        if (a[l] > x) l = 0;
        // cout << l << ' ' ;
        if (l == 0) {
            cout << a[1] - 1 << '\n';
        } else if (l == m) {
            cout << n - a[m] << '\n';
        } else {
            cout << (a[l + 1] - a[l]) / 2 << '\n';
        }
    }
}
int main()
{
    #ifdef QHK
    freopen("qi.in","r",stdin);
    freopen("qi.out","w",stdout);
    #endif
    // ios::sync_with_stdio(false); cin.tie(0); 
    int T=1;
    // scanf("%d",&T);
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
