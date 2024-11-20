#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    string s;
    cin >> s;
    vector<int> bo(s.size() + 10, 0);
    stack<int> st;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == ')') {
            if (!st.empty() ) {
                bo[st.top()] = i;
                st.pop();
            } else {
                bo[i] = -1;
            }
        } else {
            st.push(i);
        }
    }
    if (!st.empty() ) {
        cout << "impossible\n";
    } else {
        cout << s << '\n';
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
    cin >> T;
    while(T--) {
        work();
    }

   return 0;
}
