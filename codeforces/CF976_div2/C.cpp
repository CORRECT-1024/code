#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL b, c, d;
    cin >> b >> c >> d;
    vector<int> ans(100, 0);
    bool bo = true;
    ULL num = 0, p = 1;
    for (int i=0; i<=61; i++) {
        int fb = (b & 1) , fc = (c & 1) , fd = (d & 1);
        b >>= 1;  c >>= 1;  d >>= 1;
        if (fc ) {
            if (fb )  ans[i] = 1 - fd;
            else if (fd ) {
                bo = false;  break;
            }
        } else {
            if (!fb )  ans[i] = fd;
            else if (!fd ) {
                bo = false;  break;
            }
        }
        if (ans[i]) num += p;
        p <<= 1;
    }
    if (num > ((ULL)1 << 61)) bo = false;
    if (bo) {
        cout << num << '\n';
    } else {
        cout << -1 << '\n';
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
