#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N = 2e5 + 10;

// int xds[N * 4];

// void build(int k, int l, int r, vector<int>&a) {
//     if (l == r) {
//         xds[k] = a[l];
//         return;
//     }
//     int mid = ((l + r) >> 1);
//     build(2*k, l, mid, a);
//     build(2*k+1, mid+1, r, a);
//     xds[k] = min(xds[])
// }

void work() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n+10, 0);
    map<int, int> mp;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    vector<int> b(m+10, 0);
    vector<priority_queue<int, vector<int>, greater<>> > pri(n+10);
    for (int i=1; i<=n; i++) {
        pri[i].push(m + i);
    }
    for (int i=1; i<=m; i++) {
        cin >> b[i];
        b[i] = mp[b[i]];
        pri[b[i]].push(i);
    }
    vector<int> d(n+10, 0);
    stack<int> st;
    for (int i=1; i<n; i++) {
        d[i] = pri[i + 1].top() - pri[i].top();
        if (d[i] < 0) {
            st.push(i);
        }
    }
    if (st.empty()) {
        cout << "YA\n";
    } else {
        cout << "TIDAK\n";
    }
    while (q --) {
        int s, t;  cin >> s >> t;
        t = mp[t];
        if (b[s] != t) {
            int del = b[s];
            int lap = pri[del].top();
            b[s] = t;
            while (pri[del].top() <= m && b[pri[del].top()] != del) {
                pri[del].pop();
            }
            int lapp = pri[t].top();
            pri[t].push(s);
            if (lap != pri[del].top()) {
                d[del - 1] += pri[del].top() - lap;
                d[del] += lap - pri[del].top();
                if (del < n && d[del] < 0) {
                    st.push(del);
                }
            }
            if (lapp != pri[t].top()) {
                d[t - 1] += pri[t].top() - lapp;
                d[t] += lapp - pri[t].top();
                if (t-1 > 0 && d[t-1] < 0) {
                    st.push(t-1);
                }
            }
            while (!st.empty()) {
                if (d[st.top()] > 0) {
                    st.pop();
                } else {
                    break;
                }
            }
        }
        if (st.empty()) {
            cout << "YA\n";
        } else {
            cout << "TIDAK\n";
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
    // scanf("%d",&T);
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
