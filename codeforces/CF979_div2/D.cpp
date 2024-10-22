#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    vector<int> bo(n+10, 0);
    map<int, int> mp;
    int id = 0;
    for (int i=1; i<=n; i++) {
        mp[a[i]] = 1;
        while (mp[id + 1] ) id ++;
        if (id == i) bo[i-1] = 1;
    }
    string s; 
    cin >> s;
    int num = 0;
    for (int i=1; i<n-1; i++) {
        if (bo[i] )  continue;
        if (s[i] == 'L' && s[i+1] == 'R') num ++;
    }
    while (m --) {
        int x;  cin >> x;
        x --;
        if (!bo[x-1] && s[x-1] == 'L' && s[x] == 'R') num --;
        if (!bo[x] && s[x] == 'L' && s[x+1] == 'R') num --;
        s[x] = 'L' + 'R' - s[x];
        if (!bo[x-1] && s[x-1] == 'L' && s[x] == 'R') num ++;
        if (!bo[x] && s[x] == 'L' && s[x+1] == 'R') num ++;
        if (num > 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
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
