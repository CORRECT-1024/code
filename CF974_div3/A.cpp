#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, k;
    cin >> n >> k;
    int num = 0, ans = 0;
    for (int i=1; i<=n; i++) {
        int x;  cin >> x;
        if (x >= k) num += x;
        if (x == 0 && num > 0) {
            ans ++;  num --;
        }
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
    // scanf("%d",&T);
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
