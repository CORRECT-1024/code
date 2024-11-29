vector<int> sz;
vector<vector<int> > scc;

void tarjan(int x, int dfncnt, vector<vector<int> > &bian, vector<int> &dfn, vector<int> &low, stack<int> &st, vector<int> &inst) {
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
            st.pop();
        }
    }
}
void tarjanfun(int n, vector<vector<int> > &bian) {
    sz = vector<int> (n+10, 0);
    vector<int> dfn(n+10, 0), low(dfn), inst(dfn);
    stack<int> st;
    for (int i=1; i<=n; i++) {
        if (dfn[i] )  continue;
        tarjan(i, 0, bian, dfn, low, st, inst);
    }
}
