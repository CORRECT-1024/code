#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, q;
    cin >> n >> q;
    string s;  cin >> s;
    int ans = 0;
    vector<int> bo(n+10, 0);
    for (int i=2; i<s.size(); i++) {
        if (s[i] == 'C' && s[i-1] == 'B' && s[i-2] == 'A')  ans ++, bo[i] = 1;
    }
    while (q --) {
        int x;  char c;
        cin >> x >> c;
        x --;
        if (bo[x + 2] == 1) {
            ans --;  bo[x + 2] = 0;
        } else if (bo[x + 1] == 1) {
            ans --;  bo[x + 1] = 0;
        } else if (bo[x] == 1) {
            ans --;  bo[x] = 0;
        }
        s[x] = c;
        if (c == 'A') {
            if (x < s.size() - 2 && s[x + 1] == 'B' && s[x + 2] == 'C') {
                bo[x + 2] = 1;  ans ++;
            }
        }
        if (c == 'B') {
            if (x < s.size() - 1 && x > 0 && s[x - 1] == 'A' && s[x + 1] == 'C') {
                bo[x + 1] = 1;  ans ++;
            }
        }
        if (c == 'C') {
            if (x > 1 && s[x - 1] == 'B' && s[x - 2] == 'A') {
                bo[x] = 1;  ans ++;
            }
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
    // scanf("%d",&T);
    // cin >> T;
    while(T--){
        work();
    }

   return 0;
}
