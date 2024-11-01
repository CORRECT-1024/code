#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << 1 << '\n' << 1 << '\n';
        return;
    }
    if (k == 1 || k == n) {
        cout << -1 << '\n';
        return;
    }
    if (((k - 1) & 1) ^ ((n - k) & 1)) {
        cout << -1 << '\n';
        return;
    }
    if ((k - 1) & 1) {
        cout << 3 << '\n';
        cout << 1 << ' ' << k << ' ' << k + 1 << '\n';
    } else {
        cout << 5 << '\n';
        cout << 1 << ' ' << 2 << ' ' << k << ' ' << k + 1 << ' ' << k + 2 << '\n';
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
