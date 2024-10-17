#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    string s;
    cin >> s;
    bool bo = true;
    if (s.size() <= 2) bo = false;
    if (bo && (s[0] != '1' || s[1] != '0') ) bo = false;
    if (bo && ((s.size() == 3 && s[2] == '1') || s[2] == '0') ) bo = false;
    if (bo) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
    while(T--){
        work();
    }

   return 0;
}
