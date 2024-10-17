#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<int> f(n+10, 1);
    for (int i=2; i<=n; i++) {
        int fa = f[i];
        while (true) {
            cout << "? " << fa << " " << i << endl;
            int x;  cin >> x;
            if (x == fa) {
                f[i] = x;
                break;
            }
            fa = x;
        }
    }
    cout << "! ";
    for (int i=2; i<=n; i++) {
        cout << f[i] << ' ' << i << ' ';
    }
    cout << endl;
}
int main()
{
    // #ifdef QHK
    // freopen("qi.in","r",stdin);
    // freopen("qi.out","w",stdout);
    // #endif
    ios::sync_with_stdio(false); cin.tie(0); 
    int T=1;
    // scanf("%d",&T);
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
