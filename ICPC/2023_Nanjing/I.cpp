#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, m;
    cin >> n >> m;
    vector<array<LL, 2 > > a(m+10);
    for (int i=1; i<=m; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    sort(&a[1], &a[m+1]);
    bool bo = true;
    a[0] = {0, 0};
    for (int i=1; i<=m; i++) {
        int d = a[i][1] - a[i-1][1];
        if (a[i][0] - a[i-1][0] == d)  continue;
        if (a[i][0] - a[i-1][0] > a[i][1]) continue;
        bo = false;  break;
    }
    if (bo) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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
    while(T--){
        work();
    }

   return 0;
}
