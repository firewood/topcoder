// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int a, b, ans = 0;
	cin >> a >> b;
	for (int i = a; i <= b; ++i) {
		stringstream ss;
		ss << i;
		string x;
		ss >> x;
		string y = x;
		reverse(y.begin(), y.end());
		ans += x == y;
	}
	cout << ans << endl;
	return 0;
}
