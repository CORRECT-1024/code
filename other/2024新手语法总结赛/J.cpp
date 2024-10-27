#include <bits/stdc++.h>
using namespace std;

void work() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n+10, 0), b(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >>a[i];
        b[a[i]] = i;
    }
    int l = 1e9, r = 0;
    for (int i=1; i<=k; i++) {
        l = min(l, b[i]);
        r = max(r, b[i]);
    }
    // cout << l << ' ' <<r << '\n';
    if (r - l + 1 == k) {
        cout << l << ' ' << r << '\n';
    } else {
        cout << "no solution\n";
    }
}
int main()
{
	int T = 1;
	cin >> T;
	while (T --) 
		work();
	return 0;
}