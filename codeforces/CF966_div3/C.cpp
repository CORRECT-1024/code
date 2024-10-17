#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<int> a(n+10, 0);
    map<int, int> mp;
    int id = 1;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if (mp.find(a[i]) == mp.end()) {
            mp[a[i]] = id;  id ++;
        }
        a[i] = mp[a[i]];
        // cout << a[i] << ' ';
    }
    // cout << '\n';
    int q;  
    cin >> q;
    while (q --) {
        string s; cin >> s;
        vector<char> bo(30, ' ');
        vector<int> fbo(30, 0);
        id = 1;
        bool ans = (s.size() == n);
        for (int i=0; i<s.size() && ans; i++) {
            if (fbo[s[i] - 'a'] == 0) {
                fbo[s[i] - 'a'] = id;
                bo[id] = s[i];  
                id ++;
            }
            if (s[i] != bo[a[i + 1]]) {
                ans = false;
            }
            // cout << fbo[s[i] - 'a'];    
        }
        // cout << '\n';
        if (ans) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
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
