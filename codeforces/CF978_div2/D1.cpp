#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    for (int i=1; i*2 <= n; i++) {
        int p1, p2;
        cout << "? " << 2*i-1 << ' ' << 2*i << endl;
        cin >> p1;
        cout << "? " << 2*i << ' ' << 2*i-1 << endl;
        cin >> p2;
        if (p1 == p2)  continue;
        int id = i == 1 ? 3 : 1, x1 = 2*i-1, x2 = 2*i;
        cout << "? " << id << ' ' << x1 << endl;
        cin >> p1;
        cout << "? " << x1 << ' ' << id << endl;
        cin >> p2;
        if (p1 == p2) {
            cout << "! " << x2 << endl;
            return;
        }
        cout << "! " << x1 << endl;
        return;
    }
    cout << "! " << n << endl;
}
int main()
{
    // #ifdef QHK
    // freopen("qi.in","r",stdin);
    // freopen("qi.out","w",stdout);
    // #endif
    ios::sync_with_stdio(false); cin.tie(0); 
    int T=1;
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
