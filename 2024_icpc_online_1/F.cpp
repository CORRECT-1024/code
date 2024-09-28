#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void work() {
    int n;
    cin >> n;
    vector<LL> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    stack<pair<LL, int> > st;
    LL ans = 0;
    st.push({1e15, 0});
    for (int i=1; i<=n; i++) {
        if (a[i] < st.top().first) {
            st.push({a[i], 1});
        } else if (a[i] == st.top().first) {
            st.top().second ++;
        } else {
            LL val = st.top().first, num = st.top().second;
            st.pop();
            if (st.top().first >= a[i]) {
                ans += num;  val = a[i];  num ++;
                if (val == st.top().first) {
                    st.top().second += num;
                } else {
                    st.push({val, num});
                }
            } else {
                while (st.top().first < a[i]) {
                    ans += num;
                    val = st.top().first;  st.top().second += num;
                    num = st.top().second;   st.pop();
                }
                ans += num;  
                val = a[i];  num ++;
                if (val == st.top().first) {
                    st.top().second += num;
                } else {
                    st.push({val, num});
                }
            }
        }
    }
    while (st.size() > 2) {
        LL val = st.top().first, num = st.top().second;
        st.pop();
        ans += num;
        st.top().second += num;
    }
    cout << ans << "\n";
}
int main()
{
    #ifdef QHK
    freopen("qi.in","r",stdin);
    freopen("qi.out","w",stdout);
    #endif
    ios::sync_with_stdio(false);  cin.tie(0);

    int T = 1;
    cin >> T;
    while (T --) {
        work();
    }

    return 0;
}