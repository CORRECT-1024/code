#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void work() {
    int n;
    cin >> n;
    vector<map<string, int> > num(30);
    for (int i=1; i<=n; i++) {
        string name, id, ac;
        cin >> name >> id >> ac;
        if (ac == "rejected") continue;
        num[id[0] - 'A'][name] ++;
    }
    int ans = 0, nu = 0;
    for (int i=0; i<26; i++) {
        int fnu = 0;
        for (auto&[_, __] : num[i]) {
            fnu ++;
        }
        if (fnu > nu) {
            nu = fnu;  ans = i;
        }
    }
    char cans = 'A' + ans;
    cout << cans << '\n';
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