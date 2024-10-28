#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    LL ans = 0;
    string s;
    cin >> s;
    vector<LL> id1, id0;
    for (int i=0; i<n; i++) {
        if (s[i] == '1') id1.push_back(i + 1);
        else id0.push_back(i + 1);
    }
    map<int, int> mp;
    int delid1 = 0, delid0 = id0.size();
    for (int i=n; i>=1; i--) {
        if (mp[i] ) continue;
        if (s[i-1] == '0') {
            ans += i;  continue;
        }
        while (delid0 && id0[delid0-1] > i) delid0 --;
        if (delid0) {
            delid0 --;
            ans += id0[delid0];
            mp[id0[delid0]] = 1;
            continue;
        }
        if (delid1 < id1.size() && id1[delid1] < i) {
            ans += id1[delid1];
            mp[id1[delid1]] ++;
            delid1 ++;
            continue;
        }
        ans += i;
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
