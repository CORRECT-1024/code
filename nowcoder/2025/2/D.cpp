//看错了，以为a、b在两个不同的字符串上
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    map<char, int> mp;
    for (int i=0; i<n; i++) {
        if (mp.find(s[i]) == mp.end()) {
            mp[s[i]] = i;
        } else {
            ans = max(ans, mp[s[i]] + 1);
            mp[s[i]] = i;
        }
    }
    mp.clear();
    for (int i=n-1; i>=0; i--) {
        if (mp.find(s[i]) == mp.end()) {
            mp[s[i]] = i;
        } else {
            ans = max(ans, n - mp[s[i]]);
            mp[s[i]] = i;
        }
    }
    if (ans == 1) ans = 0;
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
    // cin >> T;
    while(T--) {
        work();
    }

   return 0;
}
