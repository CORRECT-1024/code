#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL a, b;
    cin >> a >> b;
    a --;
    LL idr = 2, idl = 0;
    LL lr = 1e18;
    while (true) {
        if (idl>sqrt(a) and idr>sqrt(b)) break;
        LL ll = a / (idl + 1) + 1;
        LL rl = b / (idr + 1) + 1, rr = b / idr;
        if (idl > idr - 2) {
            idr ++;  continue;
            // lr = ll - 1;
            // idl ++;  continue;
        }
        if (rl > lr) {
            idr ++;  continue;
        }
        if (ll > rr) {
            lr = ll - 1;
            idl ++;  continue;
        }
        // if (lr >= rl && rr >= ll) {
        cout << min(lr, rr) << '\n';
        return;
        // }
    }
    LL L=1,R=sqrt(b)+1;
    while (L<R){
        LL mid=(L+R+1)/2;
        LL idxiao=a/mid,idda=b/mid;
        if (idda-idxiao>=2) L=mid;
        else R=mid-1;
    }
    cout<<L<<'\n';
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
