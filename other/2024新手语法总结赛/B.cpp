#include <bits/stdc++.h>
using namespace std;

void work() {
    int n;
    cin >> n;
    if (n & 1) {
        cout << "0\n";
    } else {
        cout << "1\n";
    }
}
int main()
{
	int T = 1;
// 	cin >> T;
	while (T --) 
		work();
	return 0;
}