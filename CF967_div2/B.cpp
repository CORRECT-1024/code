#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    if (n & 1) {
        for (int i=1; i<(n + 1) / 2; i++) {
            cout << n - (i - 1) * 2 << ' ';
        }
        cout << 1 << ' ';
        for (int i=1; i<(n + 1) / 2; i++) {
            cout << i * 2 << ' ';
        }
        cout << '\n';
    } else {
        cout << "-1\n";
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
