#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int a, b;
    cin >> a >> b;
    b %= 2;
    if (b == 0 && a % 2 == 1) {
        cout << "NO\n";
        return;
    }
    if (b && (a < 2 || (a - 2) % 2 == 1)) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
