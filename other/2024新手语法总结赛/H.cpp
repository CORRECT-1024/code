#include <bits/stdc++.h>
using namespace std;

void work() {
    int n, m;
    cin >> n >> m;
    int k = 0, d = 0;
    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;
        for (int j=0; j<s.size(); j++) {
            if (s[j] == 'K') {
                k ++;
            } else if (s[j] == 'D') {
                d ++;
            }
        }
    }
    if (k > d) {
        cout << "Kokomi\n";
    } else if (k < d) {
        cout << "Dodola\n";
    } else {
        cout << "Draw\n";
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