// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int a, b;
	cin >> a >> b;
	int len = max(a, b);
	string x = to_string(min(a, b));
	string ans;
	for (int i = 0; i < len; ++i) {
		ans += x;
	}
	cout << ans << endl;
	return 0;
}
