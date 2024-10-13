#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

bool fun(LL x, vector<LL> b, LL sum) {
    LL p = 1;
    for (int i=0; i<40; i++) {
        if (i && b[i] > b[i-1]) return false;
        if (b[i] > x)  return false;
        LL mx = x;
        if (i ) mx = b[i-1];
        LL d = mx - b[i];
        d /= 2;
        b[i] += d * 2;  b[i+1] -= d;
        sum -= p * b[i];
        p >>= 1;
        if (sum <= 0)  break;
    }
    return true;
}
void work() {
    int n;
    cin >> n;
    vector<LL> b(50, 0);
    LL sum = 0;
    for (int i=1; i<=n; i++) {
        int x;  cin >> x;
        sum += x;
        for (int j=0; x; j++) {
            if (x & 1) {
                b[j] ++;
            }
            x >>= 1;
        }
    }
    LL l = 0, r = sum;
    while (l < r) {
        LL mid = ((l + r ) >> 1);
        if (fun(mid, b, sum) ) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
    // for (int i=0; i<10; i++) cout << b[i] << ' ';
    // cout << '\n';
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
