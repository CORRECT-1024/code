#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == 'L')  continue;
        if (i && s[i-1] == 'L')  continue;
        if (i < s.size() - 1 && s[i+1] == 'L')  continue;
        s[i] = 'C';
    }
    cout << s << '\n';
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
