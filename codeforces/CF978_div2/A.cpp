#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, r;
    cin >> n >> r;
    int p = 0, num = 0;
    for (int i=1; i<=n; i++) {
        int a;  cin >> a;
        p += a / 2;
        if (a & 1)  num ++;
    }
    int ans = p * 2;
    ans += min(num, r - p) - max(0, num - (r - p));
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
