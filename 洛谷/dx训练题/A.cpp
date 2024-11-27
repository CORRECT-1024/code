#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a[0] == 'y' && b[0] == 'y' && c == "ding" && d == "zhen") {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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
    while(T--) {
        work();
    }

   return 0;
}
