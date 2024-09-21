#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void work() {
    int n; 
    cin >> n;
    LL k = sqrt(2 * n);
    LL p1 = 2 * n + k * k - k, q1 = 2 * k;
    LL d = __gcd(p1, q1);  p1 /= d;  q1 /= d;
    k --;
    LL p2 = 2 * n + k * k - k, q2 = 2 * k;
    if (k <= 0) {
        p2 = 1e9; q2 = 1;
    } else {
        d = __gcd(p2, q2);  p2 /= d;  q2 /= d;
    }
    k += 2;
    LL p3 = 2 * n + k * k - k, q3 = 2 * k;
    if (k > n) {
        p3 = 1e9;  q3 = 1;
    } else {
        d = __gcd(p3, q3);  p3 /= d;  q3 /= d;
    }
    double ans1, ans2, ans3;
    ans1 = (double)p1 / q1;
    ans2 = (double)p2 / q2;
    ans3 = (double)p3 / q3;
    if (ans1 <= ans2 && ans1 <= ans3) {
        cout << p1 << ' ' << q1 << '\n';
    } else if (ans2 <= ans1 && ans2 <= ans3) {
        cout << p2 << ' ' << q2 << '\n';
    } else {
        cout << p3 << ' ' << q3 << '\n';
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