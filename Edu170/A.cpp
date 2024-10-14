#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    string s1, s2;
    cin >> s1 >> s2;
    int ans = s1.size() + s2.size();
    int len = min(s1.size(), s2.size());
    for (int i=0; i<len; i++) {
        if (s1[i] == s2[i]) {
            if (i ) ans --;
        } else break;
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
