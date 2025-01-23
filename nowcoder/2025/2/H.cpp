#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b - a == 1 && d - c == 1) {
        cout << a << ' ' << d << '\n';
        cout << a << ' ' << c << '\n';
        cout << b << ' ' << c << '\n';
        return;
    }
    if (b - a <= d - c) {
        cout << a << ' ' << d << '\n';
        cout << a << ' ' << d - 1 << '\n';
        cout << a + 1 << ' ' << c << '\n';
    } else {
        cout << a << ' ' << d-1 << '\n';
        cout << b << ' ' << d << '\n';
        cout << b - 1 << ' ' << d << '\n';
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
