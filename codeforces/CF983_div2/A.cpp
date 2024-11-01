#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    int m = 2 * n;
    vector<LL> a(m+10, 0);
    int num = 0;
    for (int i=1; i<=m; i++) {
        cin >> a[i];
        if (a[i] == 1)  num ++;
    }
    int ans = min({n, num, m - num});
    int mians = 0;
    if (num & 1) mians = 1;
    cout << mians << ' ';
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
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
