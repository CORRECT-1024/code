#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    srand(time(0));
    int n = 7;
    int m = n + rand() % n;
    int q = n;
    cout << n << ' ' << m << ' ' << q << '\n';
    for (int i=1; i<=m; i++) {
        int u, w;
        u = rand() % n;
        w = (rand() - rand()) * (rand() - rand()) % n;
        cout << u << ' ' << w << '\n';
    }
    for (int i=1; i<=q; i++) {
        cout << i - 1 << '\n';
    }
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
