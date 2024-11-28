#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

vector<int> sz;
vector<vector<int> > scc;

void tarjan(int x, int dfncnt, vector<vector<int> > &bian, vector<int> &dfn, vector<int> &low, stack<int> &st, vector<int> inst) {
    dfncnt ++;  dfn[x] = dfncnt;  low[x] = dfncnt;
    st.push(x);  inst[x] = 1;
    for (auto &to : bian[x]) {
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
            sz[st.top()] = scc.size() - 1;
            st.pop();
        }
    }
}
void tarjanfun(int n, vector<vector<int> > &bian) {
    sz = vector<int> (n+10, 0);
    vector<int> dfn(n+10, 0), low(dfn), inst(dfn);
    stack<int> st;
    tarjan(1, 0, bian, dfn, low, st, inst);
}
void work() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > bian(n+10, vector<int>());
    for (int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        bian[u].push_back(v);
    }
    tarjanfun(n, bian);
    for (int i=0; i<scc.size(); i++) {
        cout << i << '\n';
        for (auto &x : scc[i]) {
            cout << x << ' ';
        }
        cout << '\n';
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
