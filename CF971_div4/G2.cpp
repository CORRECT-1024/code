//线段树好像能写？
//查找一次区间答案，好像是3log？
//好像build不好写，时间复杂度好像会爆？
//题解真是天才想法，甚至bulid都不用写了
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N = 2e5 + 10;

LL xds[N * 4], lazy[N * 4];
LL xdsa[N];

void build(int k, int l, int r) {
    if (l == r) {
        // xds[k] = a[l];
        xds[k] = 0;  lazy[k] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(2*k, l, mid);
    build(2*k+1, mid + 1, r);
    xds[k] = 0;  lazy[k] = 0;
}
void check(int k, int l, int r, int id, int val) {
    if (r < id) return;
    if (l == r) {
        xds[k] = val;
        // xdsa[k] = val;
        return;
    }
    int mid = ((l + r) >> 1);
    if (id <= mid) check(2*k, l, mid, id, val);
    else check(2*k+1, mid+1, r, id, val);
    xds[k] = xds[2*k] + xds[2*k+1];
}
void push(int k, int l, int r) {
    xds[k] = lazy[k] * (r - l + 1);
    if (l < r) {
        lazy[2*k] = max(lazy[2*k], lazy[k]);
        lazy[2*k+1] = max(lazy[2*k+1], lazy[k]);
    }
    lazy[k] = 0;
}
void check1(int k, int l, int r, int al, int ar, LL val) {
    if (l >= al && r <= ar) {
        lazy[k] = max(lazy[k], val);
        push(k, l, r);
        return;
    }
    push(k, l, r);
    int mid = ((l + r) >> 1);
    if (al <= mid)  check1(2*k, l, mid, al, ar, val);
    if (ar > mid)  check1(2*k+1, mid+1, r, al, ar, val);
    xds[k] = xds[2*k] + xds[2*k+1];
}

LL query(int k, int l, int r, int al, int ar) {
    if (lazy[k] )  push(k, l, r);
    if (l >= al && r <= ar) {
        return xds[k];
    }
    int mid = ((l + r) >> 1);
    LL ans = 0;
    if (al <= mid) ans = query(2*k, l, mid, al, ar);
    if (ar > mid) ans += query(2*k+1, mid+1, r, al, ar);
    return ans;
}

bool operator<(array<int, 2>&x, array<int, 2>&y) {
    return x[0] < y[0];
}
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
    // for (int i=1; i<=n; i++) {
    //     cout << ans[i] << ' ';
    // }
    // cout << '\n';
    // return;
    vector<array<int, 3> > qu(q+10);
    for (int i=1; i<=q; i++) {
        cin >> qu[i][0] >> qu[i][1];
        qu[i][1] -= k - 1;
        qu[i][2] = i;
    }
    sort(&qu[1], &qu[q+1], [&](array<int, 3>&x, array<int, 3>&y) {
        return x[0] > y[0];
    });
    // for (int i=1; i<=q; i++) {
    //     cout << qu[i][0] << ' ' << qu[i][1] << '\n';
    // }
    // cout << '\n';
    // return;
    build(1, 1, n);
    vector<LL> endans(q+10, 0);
    int qid = 1;
    vector<array<int, 2> > stk(n+10);
    int stkid = 0;
    for (int i=n; i>=1; i--) {
        check(1, 1, n, i, ans[i]);
        if (stkid == 0) {
            stk[stkid][0] = ans[i];
            stk[stkid][1] = i;
            stkid ++;
        } else {
            bool bo = false;
            while (stkid && stk[stkid-1][0] < ans[i]) {
                stkid--;  bo = true;
            }
            if (bo && stkid)  check1(1, 1, n, i + 1, stk[stkid-1][1] - 1, ans[i]);
            else if (bo) check1(1, 1, n, i + 1, n, ans[i]);
            stk[stkid][0] = ans[i];   stk[stkid][1] = i;
            stkid ++;
        }
        while (qid <= q && qu[qid][0] == i) {
            LL num = k * (qu[qid][1] - qu[qid][0] + 1) - query(1, 1, n, i, qu[qid][1]);
            endans[qu[qid][2]] = num;
            qid ++;
        }
    }
    for (int i=1; i<=q; i++) {
        cout << endans[i] << '\n';
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
