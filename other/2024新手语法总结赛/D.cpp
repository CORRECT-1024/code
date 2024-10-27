#include <bits/stdc++.h>
using namespace std;

void work() {
    int n;
    cin >> n;
    long long p1 = 1, p2 = 1;
    for (int i=2; i<=n; i++) {
        long long p = p1 + p2;
        p2 = p1;
        p1 = p;
    }
    cout << p1 << '\n';
}
int main()
{
	int T = 1;
// 	cin >> T;
	while (T --) 
		work();
	return 0;
}