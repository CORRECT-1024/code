#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<LL> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    string s;
    cin >> s;
    LL ans = 0;
    queue<int> qu;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == 'L') {
            qu.push(i);
        }
    }
    for (int i=s.size() - 1; i>=0; i--) {
        if (s[i] == 'R') {
            if (qu.empty() || qu.front() > i)  break;
            ans += a[i+1] - a[qu.front()];
            qu.pop();
        }
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
