//不会set导致的。。。
//用set，每次删除两个，加两个，O(nlog)
//明天在写
//丸辣，老眼昏花，看错题啦
//奥，没看错
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

bool operator<(array<int, 2>&x, array<int, 2>&y) {
    return x[0] < y[0];
}
void work() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        a[i] -= i;
        // cout << a[i] << ' ';
    }
    // cout << '\n';
    vector<int> ans(n+10, 0);
    // priority_queue<pair<int, int>, vector<pair<int, int> >, less<> > pri;
    set<array<int, 2> > st;
    map<int, int> mp, mp1;
    for (int i=1; i<k; i++) {
        mp[a[i]] ++;
    }
    for (auto&[ai, num] : mp) {
        // pri.push({num, ai});
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
        // if (mp1[a[i]] == 0) {
        //     pri.push({mp[a[i]], a[i]});
        //     mp1[a[i]] = 1;
        // }
        // while (pri.top()[0] != mp[pri.top()[1]]) {
        //     auto t = pri.top();  pri.pop();
        //     t[0] = mp[t[1]];
        //     pri.push(t);
        // }
        // for (auto k = st.begin(); k != st.end(); k ++) {
        //     cout << (*k)[0] << ' ';
        // }
        // cout << '\n';
        auto p = st.end();  p --;
        ans[i] = (*p)[0];
        // if (mp1[a[i]] > pri.top()[0]) {

        // }
    }
    while (q --) {
        int l, r;  cin >> l >> r;
        cout << k - ans[r] << '\n';
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
