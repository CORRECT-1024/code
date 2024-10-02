/*
题解二分的l是不符合的,把代码中的l都换成l-1就对味了
题解的二分写法，有时间仔细看看
现在太困了。。。
sqrt还能爆???涨见识了
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long k, l = 1, r = 2e18;
        cin >> k;
        while(r-l > 1){
            long long mid = (l+r)>>1;
            long long n = mid - int(sqrtl(mid));
            if(n >= k) r = mid;
            else l = mid;
        }
        cout << r << "\n";
    }
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL k;
    cin >> k;
    cout << k + (LL)(sqrtl(k) + 0.5) << '\n';
    cout << k + (LL)(sqrt(k) + 0.5) << '\n';

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
