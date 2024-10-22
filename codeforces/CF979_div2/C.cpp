#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool bo = false;
    for (int i=1; i<n; i++) {
        if (s[i] == '1' && s[i-1] == '1') {
            bo = true; break;
        }
    }
    if (s[0] == '1' || s[n-1] == '1') bo = true;
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
