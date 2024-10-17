#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int m;
    cin >> m;
    int n = 0;
    vector<int> ans;
    int p = 0;
    while (m) {
        if (m % 3 == 1) {
            n ++;
            ans.push_back(p);
        } else if (m % 3 == 2) {
            n += 2;
            ans.push_back(p);
            ans.push_back(p);
        }
        m /= 3;
        p ++;
    }
    cout << n << '\n';
    for (int i=0; i<n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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
    // cin >> T;
    while(T--){
        work();
    }

   return 0;
}
