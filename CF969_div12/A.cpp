#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<int> du(n+10, 0);
    string s;
    // vector<int> ye;
    for (int i=1; i<n; i++) {
        int u, v;  cin >> u >> v;
        du[u] ++;   du[v] ++;
    }
    cin >> s;
    int sum = 0;
    for (int i=0; i<s.size(); i++) 
        if (s[i] == '?') sum ++;
    int num = 0, num1 = 0, num0 = 0;
    for (int i=2; i<=n; i++) {
        if (du[i] == 1) {
            if (s[i - 1] == '?')  num ++;
            else if (s[i - 1] == '0')  num0 ++;
            else num1 ++;
        }
    }
    int ans = 0;
    if (s[0] == '0') {
        ans = num1 + (num + 1) / 2;
    } else if (s[0] == '1') {
        ans = num0 + (num + 1) / 2;
    } else {
        ans = max(num1, num0) + num / 2;
        if (num1 == num0) {
            if ((sum - num - 1) % 2 == 0)  num --;
            ans = max(ans, num1 + (num + 1) / 2);
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
    // scanf("%d",&T);
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
