#include <bits/stdc++.h>
using namespace std;

void work() {
    int n;
    cin >> n;
    vector<int> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >>a[i];
    }
    sort(&a[1], &a[n+1]);
    int id = n+1;
    for (int i=1; i<=n; i++) {
        if (a[i] >= 0) {
            id = i;  break;
        }
    }
    for (int i=id-1; i>=1; i--) {
        cout << a[i] << ' ';
    }
    for (int i=id; i<=n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}
int main()
{
	int T = 1;
	cin >> T;
	while (T --) 
		work();
	return 0;
}