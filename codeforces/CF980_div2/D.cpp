//看到tag上的最短路想到了解法
//其实自己也往图论上想了，甚至想过会不会向后移到各个位置然后全向前，但是图论想了一会生成树（生成链？），想偏了
// 看了下题，又看了下上面两行注释，严重怀疑我写这注释的时候已经神志不清了
// 这题不就是pri代替线段树维护dp吗？和图论什么关系
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<LL> a(n+10, 0), b(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> b[i];
    }
    vector<LL> dp(n+10, (LL)1e16);
    dp[1] = 0;
    priority_queue<LL, vector<LL>, greater<> > pri;
    priority_queue<array<LL, 2>, vector<array<LL, 2> >, greater<> > del;
    map<LL, int> mp;
    LL sum = 0, ans = 0;
    for (int i=1; i<=n; i++) {
        while (!del.empty() && del.top()[0] == i) {
            mp[del.top()[1]] --;  del.pop();
        }
        while (!pri.empty() && mp[pri.top()] == 0) {
            pri.pop();
        }
        if (!pri.empty() )  dp[i] = min(dp[i], pri.top());
        sum += a[i];
        // cout << sum << ' ' << dp[i] << '\n';
        ans = max(ans, sum - dp[i]);
        if (b[i] <= i)  continue;
        LL p = dp[i] + a[i];
        pri.push(p);  mp[p] ++;
        del.push({b[i] + 1, p});
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
    while(T--){
        work();
    }

   return 0;
}
