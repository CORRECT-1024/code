#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

bool cmp(int x, int y) {
    return x > y;
}
void work() {
    vector<int> a(40);
    for (int i=1; i<=32; i++) {
        cin >> a[i];
    }
    int k = a[1];
    sort(&a[1], &a[33], cmp);
    int id = 0;
    for (int i=1; i<=32; i++) {
        if (a[i] == k) {
            id = i;  break;
        }
    }
    if (id >= 31) {
        cout << "32\n";
    } else if (id >= 27) {
        cout << "16\n";
    } else if (id >= 20) {
        cout << "8\n";
    } else if (id >= 6) {
        cout << "4\n";
    } else if (id >= 2) {
        cout << "2\n";
    } else {
        cout << "1\n";
    }
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