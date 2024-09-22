#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<LL> a(n+10, 0);
    stack<array<LL, 3> > st;
    for (int i=1; i<=n; i++)   cin >> a[i];
    vector<LL> b(n+10, 0);
    for (int i=1; i<=n; i++) {
        b[i] = a[n + 1 - i];
    }
    swap(a, b);
    for (LL i=1; i<=n; i++) {
        if (st.empty() ) {
            st.push(array{a[i], i, i});
            continue;
        }
        if (a[i] == st.top()[0]) {
            st.top()[2] = i;
        } else if (a[i] < st.top()[0]) {
            st.push(array{a[i], i, i});
        } else {
            LL sum = a[i], len = 1;
            while (!st.empty() && (sum - 1) / len + 1 >= st.top()[0]) {
                sum += st.top()[0] * (st.top()[2] - st.top()[1] + 1);
                len += st.top()[2] - st.top()[1] + 1;
                st.pop();
            }
            LL k1, p1, k2, p2;
            k1 = (sum - 1) / len + 1;  p1 = sum % len;
            k2 = sum / len;  p2 = len - p1;
            if (p1 ) st.push(array{k1, i - len + 1, i - p2});
            if (p2 ) st.push(array{k2, i - p2 + 1, i});
        }
    }
    LL mx = 0, mi = 1e15;
    while (!st.empty() ) {
        // cout << st.top()[0] << ' ' << st.top()[1] << ' ' << st.top()[2] << '\n';
        LL x = st.top()[0];  st.pop();
        mx = max(mx, x);  mi = min(mi, x);
    }
    cout << mx - mi << '\n';
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
