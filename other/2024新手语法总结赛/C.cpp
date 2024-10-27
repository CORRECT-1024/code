#include <bits/stdc++.h>
using namespace std;

void work() {
    int n;
    cin >> n;
    if (n % 3) {
        cout << 0 << '\n';
        return;
    }
    long long ans = 1;
    for (int i=1; i<=n/3; i++) {
        ans *= 2;
    }
    cout << ans << '\n';
}
int main()
{
	int T = 1;
// 	cin >> T;
	while (T --) 
		work();
	return 0;
}