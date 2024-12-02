#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    string a, b, na, nb;
    cin >> a >> b >> na >> nb;
    int a1 = 0, a0 = 0, b1 = 0, b0 = 0;
    int ida = -1, idb = -1;
    int ans = 0;
    for (int i=0; i<n; i++) {
        if (ida < i) {
            ida = i;  
            if (a[ida] == '1')  a1 = 1;
            else a0 = 1;
            while (ida + 1 < n && na[ida + 1] == '1' && na[ida] == '1') {
                ida ++;  
                if (a[ida] == '1')  a1 ++;
                else a0 ++;
            }
        }
        if (idb < i) {
            idb = i;  
            if (b[idb] == '1')  b1 = 1;
            else b0 = 1;
            while (idb + 1 < n && nb[idb + 1] == '1' && nb[idb] == '1') {
                idb ++;  
                if (b[idb] == '1')  b1 ++;
                else b0 ++;
            }
        }
        // cout << i << ' ' << ida << ' ' << idb << '\n';
        // cout << "a0 : " << a0 << " a1 : " << a1 << '\n';
        // cout << "b0 : " << b0 << " b1 : " << b1 << '\n';
        if (a1 && b1) {
            ans ++;
            a1 --;  b1 --;
        } else if (a0 && b0) {
            ans ++;
            a0 --;  b0 --;
        } else if (a1 && b0) {
            a1 --;  b0 --;
        } else {
            a0 --;  b1 --;
        }
        // cout << "ans : " << ans << '\n';
    }
    cout << ans << '\n';
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
    while(T--) {
        work();
    }

   return 0;
}
