//线段树好像能写？
//查找一次区间答案，好像是3log？
//好像build不好写，时间复杂度好像会爆？
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N = 2e5 + 10;

int xds1[N * 4];
LL xds2[N * 4];

void build(int k, int l, int r, vector<int> &a) {
    if (l == r) {
        xds1[k] = a[l];  xds2[k] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build()
}

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
