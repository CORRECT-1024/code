#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int ans = 0, n;
    cin >> n;
    int p = -1;
    for (int i=1; ; i++) {
        ans += p * (2 * i - 1);
        if (abs(ans) > n) {
            if (i & 1) {
                cout << "Sakurako\n";
            } else {
                cout << "Kosuke\n";
            }
            return;
        }
        p *= -1;
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
