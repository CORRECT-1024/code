//vis如果开成int的话，cf报了CE，有时间仔细看看
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N = 1e7 + 10;

bool vis[N];
vector<int> p;
map<int, int> mp;

void getPrime(){//查找1到N之间的质数 
	for(int i=2; i < N; i++) vis[i]=true;

	for(int i=2; i < N; i++){
        if(vis[i] ) {
            p.push_back(i);
            mp[i] = p.size();
        }

        for(int j=0; p[j] <= N / i && j < p.size(); j++) {
            vis[p[j] * i] = false;
            if(i % p[j] == 0) break;
        }
    }
}
void work() {
    int n;
    cin >> n;
    vector<int> a(n+10);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            a[i] = 0;  continue;
        }
        if (a[i] == 1) continue;
        if (vis[a[i]] ) {
            a[i] = mp[a[i]]; continue;
        }
        for (int j=0; p[j] < a[i]; j++) {
            if (a[i] % p[j] == 0) {
                a[i] = j + 1;
                break;
            }
        }
    }
    // for (int i=1; i<=n; i++) {
    //     cout << a[i] << ' ';
    // }
    // cout << '\n';
    // sort(&a[1], &a[n+1]);
    int ans = 0;
    for (int i=1; i<=n; i++) {
        ans ^= a[i];
        // if (a[i] < ans)  continue;
        // if (a[i] == ans) {
        //     ans ++;  continue;
        // }
        // if (a[i] > ans) {
        //     break;
        // }
    }
    if (ans ) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
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
    getPrime();
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
