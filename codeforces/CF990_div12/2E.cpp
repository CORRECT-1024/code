// 离散化 + xds + 扫描线 + 二（三）分？？？
// 能二（三）分吗？
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<array<int, 2> > a(n+10);
    for (int i=1; i<=n; i++) {
        cin >> a[i][0] >> a[i][1];
        to[a[i][0]] = 1;  
        to[a[i][1]] = 1;
    }
    sort(&a[1], &a[n+1]);
    map<int, int> to;
    int toid = 1;
    for (auto &[_, id] : to) {
        id = toid;  toid ++;
    }
    for (int i=1; i<=n; i++) {
        a[i][0] = to[a[i][0]];
        a[i][1] = to[a[i][1]];
    }
    int ans = 0, id = 0, num = 0;
    build1(1, 1, toid, a);
    build(1, 1, toid);
    for (int i=1; i<=toid; i++) {
        bool bo = false;
        while (id < n && a[id + 1][0] <= i) {
            bo = true;  num ++;
            add(1, 1, toid, a[id + 1][1]);
            pop(1, 1, toid, a[id + 1][1]);
            id ++;
        }
        if (!bo)  continue;
        int l = 1, m = 2, r = toid;
        int numl = 0, numm, numr = 0;
        // int num4 = find(1, 1, toid, m), num2 = find1(1, 1, toid, m);
        // int num3 = num - num4, num1 = n - num - num2;
        // numm = min({num1, num2, num3, num4});
        while (l < r - 1) {
            int len = (r - l + 2) / 3;
            int mid1 = l + len, mid2 = r - len;
            int ansmid1 = fun(mid1), ansmid2 = fun(mid2);
            if (ansmid1 )
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
