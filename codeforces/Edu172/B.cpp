#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<int> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        int x;  cin >> x;
        a[x] ++;
    }
    int num1 = 0, numd = 0;
    for (int i=1; i<=n; i++) {
        if (a[i] == 0)  continue;
        if (a[i] == 1)  num1 ++;
        else numd ++;
    }
    int ans = (num1 + 1) / 2;
    ans *= 2;
    ans += numd;
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
    while(T--) {
        work();
    }

   return 0;
}
