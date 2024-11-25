// 怎么一直在in queue
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<int> a(n+10, 0);
    for (int i=1; i<=n; i++)   cin >> a[i];
    int ma = -1;
    priority_queue<int, vector<int>, greater<> > pri;
    map<int, int> mp;
    for (int i=n; i>=1; i--) {
        if (mp[a[i]] == 0) {
            pri.push(a[i]);
        }
        mp[a[i]] ++;
    }
    vector<int> ans(n+10, 0);
    int id = 1;
    for (int i=1; i<=n; i++) {
        ma = max(ma, a[i]);
        if (i == n) {
            ans[id] = ma;  break;
        }
        mp[a[i]] --;
        while (!pri.empty() && mp[pri.top()] == 0)  pri.pop();
        if (ma <= pri.top()) {
            ans[id] = ma;  id = i + 1;  ma = -1;
        }
    }
    int ansnum = -1;
    for (int i=1; i<=n; i++) {
        if (ans[i] )  ansnum = ans[i];
        cout << ansnum << ' ';
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
