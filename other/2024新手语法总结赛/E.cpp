#include <bits/stdc++.h>
using namespace std;

void work() {
    string s1, s2;
    cin >> s1 >> s2;
    int ma1 = 0, mi1 = 0, ma2 = 0, mi2 = 0;
    for (int i=0; i<5; i++) {
        if (s1[i] == 'Y')  {
            mi1 ++;  ma1 ++;
        } else if (s1[i] == '-') {
            ma1 ++;
        }
        if (s2[i] == 'Y') {
            mi2 ++;  ma2 ++;
        } else if (s2[i] == '-') {
            ma2 ++;
        }
    }
    if (mi1 > ma2) {
        cout << "Manchester City\n";
    } else if (mi2 > ma1) {
        cout << "Real Madrid\n";
    } else {
        cout << "We don't know what the future holds\n";
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