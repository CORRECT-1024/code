#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        a[i] -= i;
    }
    vector<int> ans(n+10, 0);
    set<array<int, 2> > st;
    map<int, int> mp, mp1;
    for (int i=1; i<k; i++) {
        mp[a[i]] ++;
    }
    for (auto&[ai, num] : mp) {
        st.insert({num, ai});
    }
    for (int i=k; i<=n; i++) {
        if (mp[a[i]] ) st.erase({mp[a[i]], a[i]});
        mp[a[i]] ++;
        st.insert({mp[a[i]], a[i]});
        if (i > k) {
            st.erase({mp[a[i-k]], a[i-k]});
            mp[a[i-k]] --;
            if (mp[a[i-k]] ) st.insert({mp[a[i-k]], a[i-k]});
        }
        auto p = st.end();  p --;
        ans[i] = (*p)[0];
    }
    vector<int> fans(ans);
    for (int i=1; i+k-1 <= n; i++) {
        fans[i] = ans[i + k - 1];
    }
    swap(fans, ans);
    n -= k - 1;
    int l = 1, id = 1;
    for (int i=2; i<=n; i++) {
        
    }
    vector<LL> sum(n+10, 0);

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
    // cin >> T;
    while(T--){
        work();
    }

   return 0;
}
