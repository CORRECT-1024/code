//先用随机数来离散化一下，就不用担心异或会撞hash了
//题解真是天才想法
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    random_device rd;
    mt19937_64 gen(rd());
    int n, q;
    cin >> n >> q;
    vector<ULL> a(n+10, 0);
    vector<ULL> has(n+10, 0);
    map<ULL, ULL> mp;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if (!mp[a[i]] ) {
            mp[a[i]] = gen();
        }
        a[i] = mp[a[i]];
        has[i] = has[i-1] ^ a[i];
    }
    while (q --) {
        int l, r;  cin >> l >> r;
        ULL p = has[r] ^ has[l - 1];
        if (p ) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
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
