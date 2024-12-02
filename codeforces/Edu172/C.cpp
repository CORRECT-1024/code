#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> a(n+10, 0);
    int d = 0;
    for (int i=n-1; i>=0; i--) {
        if (s[i] == '1')  d ++;
        else d --;
        if (i && d > 0)  a[d] ++;
    }
    int ans = 1;
    LL sum = 0;
    for (int i=n; i>=1; i--) {
        while (a[i] && sum < k) {
            ans ++;
            sum += i;
            a[i] --;
        }
        if (sum >= k)  break;
    }
    if (sum < k) {
        cout << -1 << '\n';
        return;
    }
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
