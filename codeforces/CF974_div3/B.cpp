#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, k;
    cin >> n >> k;
    int m = max(0, n - k);
    int ans = ((n + 1) / 2) & 1;
    if (((m + 1) / 2) & 1) ans ^= 1;
    if (ans ) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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
    // scanf("%d",&T);
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
