#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int mod1 = 998244353;
const int mod2 = 1e9 + 7;

ULL hash1(vector<int> &b, int n) {
    LL sum = 0;
    for (int i=1; i<=n; i++) {
        sum = sum * mod1 + b[i];
        // sum %= mod2;
    }
    for (int i=1; i<=n; i++) {
        sum = sum * mod2 + b[i];
    }
    return sum;
}
void work() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(m+10, vector<int> (n+10, 0));
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }
    LL ans = 0;
    map<ULL, int> mp;
    if (n > 9) {
        for (int i=1; i<(1 << m); i++) {
            LL p = 1;
            vector<int> b(n+10, 0);
            for (int j=1; j<=m; j++) {
                if (i & p) {
                    if (b[1] == 0) {
                        for (int k=1; k<=n; k++) {
                            b[k] = a[j][k];
                        }
                    } else {
                        vector<int> bb(b);
                        for (int k=1; k<=n; k++) {
                            bb[k] = b[a[j][k]];
                        }
                        swap(b, bb);
                    }
                }
                p <<= 1;
            }
            ULL ha = hash1(b, n);
            if (mp[ha])  continue;
            ans ++;  mp[ha] = 1;
        }
    } else {
        vector<vector<int> > qu;
        for (int i=1; i<=m; i++) {
            queue<vector<int> > fqu;
            for (auto &p : qu) {
                vector<int> b(n+10, 0);
                for (int j=1; j<=n; j++) {
                    b[j] = p[a[i][j]];
                }
                ULL ha = hash1(b, n);
                if (mp[ha] ) continue;
                mp[ha] = 1;
                ans ++;  fqu.push(b);
            }
            while (!fqu.empty() ) {
                qu.push_back(fqu.front());  fqu.pop();
            }
            ULL ha = hash1(a[i], n);
            if (mp[ha] )  continue;
            mp[ha] = 1;
            ans ++;  qu.push_back(a[i]);
        }
    }
    cout << ans << '\n';
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
