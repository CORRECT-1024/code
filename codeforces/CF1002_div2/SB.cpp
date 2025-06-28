// 狗屎啊，我写成最大成本了
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    int num = 0, ans = 1;
    int i;
    for (i=2; i<=n; i++) {
        while (i <= n && a[i] != ans) {
            i ++;
        }
        num ++;
        if (k - num > n - i + 1)  break;
        while (i <= n && a[i] == ans) {
            if (k - num > n - i + 1)  break;
            ans ++;  i ++;
        }
        num ++;
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
