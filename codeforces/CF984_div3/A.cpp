#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<int> a(n+10, 0);
    bool bo = true;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if (i > 1) {
            if (abs(a[i] - a[i-1]) != 5 && abs(a[i] - a[i-1]) != 7) {
                bo = false;
            }
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
