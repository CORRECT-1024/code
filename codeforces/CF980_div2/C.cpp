#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<array<int, 3> > a(n+10);
    for (int i=1; i<=n; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = min(a[i][0], a[i][1]);
    }
    sort(&a[1], &a[n+1], [&](array<int, 3>&x, array<int, 3>&y) {
        if (x[2] == y[2]) return x[0] + x[1] < y[0] + y[1];
        return x[2] < y[2];
    });
    for (int i=1; i<=n; i++) {
        cout << a[i][0] << ' ' << a[i][1] << ' ';
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
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
