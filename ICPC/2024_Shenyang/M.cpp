// 前几发里tarjan板子函数定义那里有个数组inst没加&引用符，导致TLE了
// 遍历强连通分量里面时，使用了拓扑排序（类似），但实际上只要有环 拓扑就可能卡住
// 写拓扑的时候，想的是通过（相当于）把一个点拆下来来把环拆开，但实际上一个强联通分量通常不会只有一个环
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const LL nonum = (LL)1e16;

vector<int> sz;
vector<vector<int> > scc;

void tarjan(int x, int dfncnt, vector<vector<array<LL, 2> > > &bian, vector<int> &dfn, vector<int> &low, stack<int> &st, vector<int> &inst) {
    dfncnt ++;  dfn[x] = dfncnt;  low[x] = dfncnt;
    st.push(x);  inst[x] = 1;
    for (auto &[to, val] : bian[x]) {
        if (!dfn[to] ) {
            tarjan(to, dfncnt, bian, dfn, low, st, inst);
            low[x] = min(low[x], low[to]);
        } else if (inst[to] ) {
            low[x] = min(low[x], low[to]);
        }
    }
    if (dfn[x] == low[x] ) {
        scc.push_back(vector<int>());
        while (inst[x] ) {
            scc[scc.size()-1].push_back(st.top());
            inst[st.top()] = 0;
            st.pop();
        }
    }
}
void tarjanfun(int n, vector<vector<array<LL, 2> > > &bian) {
    sz = vector<int> (n+10, 0);
    vector<int> dfn(n+10, 0), low(dfn), inst(dfn);
    stack<int> st;
    for (int i=0; i<n; i++) {
        if (dfn[i] )  continue;
        tarjan(i, 0, bian, dfn, low, st, inst);
    }
}

void work() {
    LL n, m, q;
    cin >> n >> m >> q;
    vector<vector<array<LL, 2> > > bian(n+10, vector<array<LL, 2> > ());
    vector<vector<int> > fubian(n+10, vector<int> ());
    vector<int> ans(n+10, 0);
    for (int i=1; i<=m; i++) {
        int u, v, w;  cin >> u >> w;
        u = (u % n + n) % n;
        v = (w % n + n) % n;
        v = (u + v) % n;
        // cout << u << ' ' << v << ' ' << w << '\n';
        if (u == v) {
            if (w == 0)  continue;
            ans[u] = 1;  continue;
        }
        bian[u].push_back({v, w});
        fubian[v].push_back(u);
    }
    for (int i=0; i<n; i++) {
        if (ans[i] ) {
            queue<int> ansqu;  ansqu.push(i);
            ans[i] = 1;
            while (!ansqu.empty() ) {
                int x = ansqu.front();  ansqu.pop();
                for (auto &u : fubian[x]) {
                    if (ans[u] == 0)  ansqu.push(u);
                    ans[u] = 1;
                }
            }
        }
    }
    tarjanfun(n, bian);
    vector<int> mp(n+10, 0);
    vector<int> mpid(n+10, 0);
    for (int sccid = 0; sccid < scc.size(); sccid ++) {
        auto &p = scc[sccid];
        // for (auto &x : p) {
        //     cout << x << ' ';
        // }
        // cout << '\n';
        if (p.size() == 1 || ans[p[0]] )  continue;
        // map<int, int> mp;
        int siz = 0;
        for (auto &x : p) {
            siz ++;  mp[x] = siz;
            mpid[x] = sccid + 1;
        }
        vector<vector<array<LL, 2> > > fbian(siz + 10, vector<array<LL, 2> > ());
        // vector<int> rudu(siz+10, 0);
        for (auto &x : p) {
            int fx = mp[x];
            for (auto &[to, val] : bian[x]) {
                // if (mp.find(to) == mp.end() )  continue;
                if (mpid[to] != sccid + 1)  continue;
                int fto = mp[to];
                fbian[fx].push_back({fto, val});
                // rudu[fto] ++;
            }
        }
        vector<LL> num(siz+10, nonum);
        num[1] = 0;
        queue<int> qu;  qu.push(1);
        bool bo = false;
        while (!qu.empty()) {
            int x = qu.front();  qu.pop();
            for (auto &[to, val] : fbian[x]) {
                if (num[to] == nonum) {
                    num[to] = num[x] + val;
                    qu.push(to);
                } else if (num[to] != num[x] + val) {
                    bo = true; break;
                }
            }
            if (bo )  break;
        }
        if (bo ) {
            queue<int> ansqu;  ansqu.push(p[0]);
            ans[p[0]] = 1;
            while (!ansqu.empty() ) {
                int x = ansqu.front();  ansqu.pop();
                for (auto &u : fubian[x]) {
                    if (ans[u] == 0)  ansqu.push(u);
                    ans[u] = 1;
                }
            }
        }
    }
    // for (int i=0; i<n; i++) {
    //     cout << i << ": " << ans[i] << '\n';
    // }
    // return;
    while (q --) {
        int x;  cin >> x;
        x = (x % n + n) % n;
        if (ans[x] ) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
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
    // cin >> T;
    while(T--) {
        work();
    }

   return 0;
}
