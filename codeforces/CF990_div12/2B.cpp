#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;  cin >> n;
    string s;  cin >> s;
    vector<int> a(30, 0);
    for (auto &c : s)  a[c - 'a'] ++;
    int mi = 1e9, mic = -1, ma = 0, mac = -1;
    for (int i=0; i<26; i++) {
        if (a[i] && a[i] < mi) {
            mi = a[i];  mic = i;
        }
        if (a[i] >= ma) {
            ma = a[i];  mac = i;
        }
    }
    // cout << mic << ' ' << mac << '\n';
    for (auto & c : s) {
        if (c - 'a' == mic) {
            c = 'a' + mac;
            mic = -1;
        }
        cout << c;
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
