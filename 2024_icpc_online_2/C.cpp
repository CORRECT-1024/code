#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void work() {
    int n;
    cin >> n;
    vector<LL> a(n+10, 0), b(n+10, 0), s(n+10, 0);
    LL ans = 0;
    LL tp = 0, sumb = 0;
    vector<int> id;
    for (int i=1; i<=n; i++) {
        cin >> s[i] >> a[i] >> b[i];
        s[i] = (s[i] + ans) % n;
        ans += b[1] * a[i];
        while (i != 1 && tp != id.size() && s[i] != s[i - id[tp] + 1]) {
            sumb -= b[id[tp]];
            tp ++;
            // tp = -1;
            // sumb = 0;
        } 
        ans += sumb * a[i];
        if (i != 1 && s[i] == s[1]) {
            id.push_back(i);
            // if (tp == -1) {
            //     tp = i;
            // }
            ans += a[i] * b[i];
            sumb += b[i];
        }
        // cout << s[i] << ' ';
        cout << ans << '\n';
    }
}
int main()
{
    #ifdef QHK
    freopen("qi.in","r",stdin);
    freopen("qi.out","w",stdout);
    #endif
    ios::sync_with_stdio(false);  cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        work();
    }

    return 0;
}