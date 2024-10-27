#include <bits/stdc++.h>
using namespace std;

void work() {
    string s;
    cin >> s;
    string s1 = s + "0";
    for (int i=s1.size()-1; i>=1; i--) {
        s1[i] += s[i-1] - '0';
    }
    cout << s1 << '\n';
}
int main()
{
	int T = 1;
	cin >> T;
	while (T --) 
		work();
	return 0;
}