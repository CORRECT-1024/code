#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    int l = -1, r = -1;
    vector<array<int, 2> > a;
    int k1 = 0;
    while (n --) {
        int p, k, num;
        cin >> p >> k >> num;
        int fl, fr;
        int al = 1, ar = num;
        while (al < ar) {
            int mid = ((al + ar - 1) >> 1);
            if ((mid + mid + k - 1) * k / 2 >= num) ar = mid;
            else al = mid + 1;
        }
        fl = l;
        al = 1, ar = num;
        while (al < ar) {
            int mid = ((al + ar - 1) >> 1);
            if ((mid + mid - k + 1) * k / 2 >= num) ar = mid;
            else al = mid + 1;
        }
        fr = l;
        if (p == 1) {
            k1 = max(k1, k);
            if (l == -1) {
                l = fl;  r = fr;
            } else {
                l = max(l, fl);  r = min(r, fr);
            }
        } else {
            a.push_back({fl, fr});
        }
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
