#include <bits/stdc++.h>
using namespace std;

void work() {
    cout << "#include <stdio.h>\nint main() {\n    int a, b;\n    scanf(\"%d + %d = ?\", &a, &b);\n    printf(\"%d + %d = %d\", a, b, a + b);\n\n    return 0;\n}";
}
int main()
{
	int T = 1;
// 	cin >> T;
	while (T --) 
		work();
	return 0;
}