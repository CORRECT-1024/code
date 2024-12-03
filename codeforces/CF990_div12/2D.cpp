#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    stack<int> st;
    vector<int> ans;
    int mi = 1e9 + 10;
    for (int i=1; i<=n; i++) {
        int x;  cin >> x;
        while (!st.empty() && x < st.top() ) {
            ans.push_back(st.top() + 1);
            mi = min(mi, st.top() + 1);
            st.pop();
        }
        st.push(x);
    }
    while (!st.empty() && st.top() > mi) {
        ans.push_back(st.top() + 1);
        st.pop();
    }
    while (!st.empty() ) {
        ans.push_back(st.top());
        st.pop();
    }
    sort(ans.begin(), ans.end());
    for (auto &x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}
int main()
{
    #ifdef QHK
    freopen("qi.in","r",stdin);
    freopen("qi.out","w",stdout);
    #endif
    ios::sync_with_stdio(false); cin.tie(0); 
    int T=1;
    cin >> T;
    while(T--) {
        work();
    }

   return 0;
}
