//建成图, 算初始答案, 对每个点存最大的两个出路
//每条边维护权值(重边数+1), ans=max(某边权值-1的答案,初始答案)
//明天再写
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL n, m;
    cin >> n >> m;
    LL mau = 0, mav = 0;
    for (int i=1; i<=n; i++) {
        int l;  cin >> l;
        vector<LL> a(l+10, 0);
        for (int i=1; i<=l; i++) {
            cin >> a[i];
        }
        sort(&a[1], &a[l+1]);
        LL u = -1, v = -1;
        int k = 0;
        for (int i=1; i<=l; i++) {
            if (a[i] < k)  continue;
            if (a[i] == k) {
                k ++;  continue;
            }
            while (a[i] > k) {
                if (u == -1)  u = k;
                else {
                    v = k;  break;
                }
                k ++;
            }
            if (a[i] == k) {
                k ++;  continue;
            }
        }
        if (u == -1) {
            u = k;  v = k + 1;
        } else if (v == -1) {
            v = k;
        }
        // cout << u << ' ' << v << '\n';
        mau = max(mau, u);
        mav = max(mav, v);
    }
    LL ans = 0;
vector<int> 

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
