// 智障了
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    string s;
    cin >> s;
    vector<int> id(50, -1);
    int l = 0, r = -1;
    for (int i=0; i<s.size(); i++) {
        if (id[s[i] - 'a'] >= l) {
            int len = i - l + 1;
            int num = (len + 1) * len / 2;
            while (num % 2 == 0 && l <= id[s[i] - 'a']) {
                l ++;
                len = i - l + 1;
                num = (len + 1) * len / 2;
            }
            if (l > id[s[i] - 'a']) {
                id[s[i] - 'a'] = i;  continue;
            }
            r = i;  break;
        }
        int len = i - l + 1;
        int num = (len + 1) * len / 2;
        if (num % 2 == 0) {
            r = i;  break;
        }
        id[s[i] - 'a'] = i;
    }
    // cout << l << ' ' << r << '\n';
    if (r == -1) {
        cout << "-1\n";
    } else {
        string ans = "";
        for (int i=l; i<=r; i++) {
            ans += s[i];
        }
        cout << ans << '\n';
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
    while(T--) {
        work();
    }

   return 0;
}
