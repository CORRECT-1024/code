#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    string s;
    cin >> s;
    int beid = -1;
    int p = 1, len = s.size();
    for (int i=0; i<s.size(); i++) {
        if (s[i] != s[(i + len - 1) % len]) {
            beid = i;  break;
        }
    }
    if (beid == -1) {
        cout << len / 2 << '\n';
        return;
    }
    vector<int> a;
    for (int i=1; i <= len; i++) {
        if (s[(beid + i) % len] != s[(beid + i - 1) % len]) {
            a.push_back(p); p = 1;
        } else {
            p ++;
        }
    }
    if (p > 1) {
        a.push_back(p);
    }
    bool bo = true;
    int ans = 0;
    for (auto & x : a) {
        // cout << x << ' ';
        if (x == 1)  continue;
        if (x & 1) {
            ans += x / 2;
            continue;
        }
        if (bo) {
            x --;  bo = false;
        }
        ans += x / 2;
    }
    // cout << '\n';
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
