// 幽默，构造想出来了，但只写了一半，另一半不写？
// 现在也没比赛啊，怎么一直在in queue
// 坏了，交成D题了
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<int> ans(n+10, 0);
    if (n % 2 == 0) {
        for (int i=1; i*2 <= n; i++) {
            cout << i << ' ' << i << ' ';
        }
        cout << '\n';
        return;
    } else if (n >= 27) {
        ans[1] = 1;  ans[10] = 1;  ans[26] = 1;
        ans[23] = 2;  ans[27] = 2;
        int id = 6;
        for (int i=1; i<=n; i++) {
            if (ans[i] )  continue;
            ans[i] = id / 2;
            id ++;
        }
        for (int i=1; i<=n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    cout << "-1\n";
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
