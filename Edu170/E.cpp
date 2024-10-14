#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int mod = 998244353;

void work() {
    int n, m;
    cin >> n >> m;
    vector<LL> p(m+10, 0);
    p[0] = 1;
    for (int i=1; i<=m; i++) {
        for (int j=i/2; j>=1; j--) {
            p[j] += p[j-1];
            p[j] %= mod;
        }
    }
    for (int i=0; i<=m/2; i++) {
        //拿几张牌，需要几张1牌，方案数
        cout << i << ' ' << m - 2 * i << ' ' << p[i] << '\n';
    }
    return;
    
    
}
int main()
{
    #ifdef QHK
    freopen("qi.in","r",stdin);
    freopen("qi.out","w",stdout);
    #endif
    ios::sync_with_stdio(false); cin.tie(0); 
    int T=1;
    // cin >> T;
    while(T--){
        work();
    }

   return 0;
}
