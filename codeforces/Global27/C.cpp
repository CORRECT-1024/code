#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    if (n == 5) {
        cout << "5\n2 1 3 4 5\n";
        return;
    } else if (n == 6) {
        cout << "7\n1 2 4 6 5 3 \n";
        return;
    } else if (n == 7) {
        cout << "7\n2 4 5 1 3 6 7 \n";
        return;
    }
    int m = n, num = 0;
    if (m & 1) m --;
    int p = 1;
    while (2 * p <= m)  p *= 2;
    vector<int> ans(n+10, 0);
    map<int, int> mp;
    if (n & 1) {
        num = n;
        ans[n] = n;
        mp[n] = 1;
    } else {
        num = p + p - 1;
    }
    ans[m] = p;  mp[p] = 1;
    ans[m-1] = p - 1;  mp[p - 1] = 1;
    ans[m-2] = p - 2;  mp[p-2] = 1;
    ans[m-3] = 1;  mp[1] = 1;
    ans[m-4] = 3;  mp[3] = 1;
    int id = 1;
    for (int i=1; i<m-4; i++) {
        while (mp[id] ) id ++;
        ans[i] = id;
        id ++;
    }
    cout << num << '\n';
    for (int i=1; i<=n; i++) {
        cout << ans[i] << ' ' ;
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
    while(T--){
        work();
    }

   return 0;
}
