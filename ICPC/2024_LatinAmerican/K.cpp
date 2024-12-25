#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int k;
    string s;
    cin >> k >> s;
    if (k == 2) {
        int ans1 = 0, ans2 = 0;
        for (int i=0; i<s.size(); i++) {
            if (i & 1) {
                if (s[i] == '0') ans1 ++;
                else ans2 ++;
            } else {
                if (s[i] == '0') ans2 ++;
                else ans1 ++;
            }
        }
        cout << min(ans1, ans2) << ' ';
        if (ans1 <= ans2) {
            for (int i=0; i<s.size(); i++) {
                if (i & 1) cout << '1';
                else cout << '0';
            }
        } else {
            for (int i=0; i<s.size(); i++) {
                if (i & 1) cout << '0';
                else cout << '1';
            }
        }
    } else {
        int ans = 0, d = 0, la = -1;
        for (int i=0; i<s.size(); i++) {
            if (s[i] - '0' == la) {
                d ++;
                if (d == k) {
                    if (i + 1 < s.size() && s[i + 1] == s[i]) s[i] = '1' + '0' - s[i];
                    else s[i-1] = '1' + '0' - s[i-1];
                    ans ++;  d = 0;
                }
            } else {
                d = 1;  la = s[i] - '0';
            }
        }
        cout << ans << ' ';
        cout << s;
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
    // cin >> T;
    while(T--) {
        work();
    }

   return 0;
}
