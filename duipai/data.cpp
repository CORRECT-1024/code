#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    srand(time(0));
    int T = 1;
    cout << T << '\n';
    int n = rand() % 10 + 3;
    cout << n << '\n';
    for (int i=1; i<=n; i++) {
        int x = rand() % (2*n) + 1;
        cout << x << ' ';
    }
    cout << '\n';
    for (int i=1; i<=n; i++) {
        int x = rand() % (2*n) + 1;
        cout << x << ' ';
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
