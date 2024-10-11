#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    bool bo = true;
    vector<int> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        int x;  cin >> x;
        a[x] = 1;
        if (i == 1)  continue;
        if (a[x-1] == 0 && a[x+1] == 0) {
            bo = false;
        }
    }
    if (bo) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
