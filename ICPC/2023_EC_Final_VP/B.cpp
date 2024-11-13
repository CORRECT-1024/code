#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    string s;
    cin >> s;
    int num = 0;
    vector<int> ans;
    for (int i=s.size()-1; i>=0; i--) {
        if (s[i] == 'I') {
            num ++;  continue;
        }
        if (num == 0 && i && s[i-1] == 'I') {
            num = -1;
            ans.push_back(4);
            continue;
        }
        if (num == 0) {
            ans.push_back(5);
            continue;
        }
        int d = num % 3;
        if (d == 0)  d = 3;
        num -= d;
        while (num) {
            ans.push_back(min(num, 3));
            num -= min(num, 3);
        }
        ans.push_back(5 + d);
    }
    while (num) {
        ans.push_back(min(num, 3));
        num -= min(num, 3);
    }
    for (int i=ans.size()-1; i>=0; i--) {
        cout << ans[i];
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
