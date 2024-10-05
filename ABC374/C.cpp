#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

LL sum = 0, ans = 0;

void dfs(int x, int n, vector<LL>&a, LL num) {
    if (x == n + 1) {
        ans = min(ans, max(num, sum - num));
        return;
    }
    dfs(x + 1, n, a, num);
    num += a[x];
    dfs(x + 1, n, a, num);
}
void work() {
    int n;
    cin >> n;
    vector<LL> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    ans = sum;
    dfs(1, n, a, 0);
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
    // cin >> T;
    while(T--){
        work();
    }

   return 0;
}
