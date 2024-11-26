#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    int la = 0;
    for (int i=1; i<=n; i++) {
        int d = (la / i) * i + i - 1;
        if (d <= la) d += i;
        // cout << i << ": " << d << '\n';
        cout << d << ' ';
        la = d;
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
    while(T--) {
        work();
    }

   return 0;
}
