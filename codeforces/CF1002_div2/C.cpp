// 看错输入了，真红温啊
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<int> a(n+10, n);
    for (int i=1; i<=n; i++) {
        for (int j=n; j>=1; j--) {
            int x;  cin >> x;
            if (x != 1)  a[i] = j - 1;
        }
    }
    sort(&a[1], &a[n+1]);
    int ans = 0;
    for (int i=1; i<=n; i++) {
        if (a[i] < ans) {
            continue;
        }
        ans ++;
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
