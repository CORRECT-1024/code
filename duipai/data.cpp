#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    srand(time(0));
    int T = 1;
    cout << T << '\n';
    int n = rand() % 100 + 3;
    cout << n << '\n';
    cout << 1 << ' '  << 2 << '\n';
    for (int i=3; i<=n; i++) {
        cout << i << ' ' << rand() % (i - 2) + 1 << '\n';
    }
    int u = rand() % (n - 1) + 2;
    cout << u << ' ' << u << '\n';
}
int main()
{
    #ifdef QHK
    // freopen("qi.in","r",stdin);
    freopen("qi.in","w",stdout);
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
