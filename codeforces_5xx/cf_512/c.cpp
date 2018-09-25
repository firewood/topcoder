// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;


int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool ans = false;
	for (int sum = 0; sum <= 1000; ++sum) {
		int t = 0, g = 0;
		for (int i = 0; i < n; ++i) {
			t += s[i] - '0';
			if (t == sum) {
				t = 0;
				++g;
			}
		}
		if (!t && g > 1) {
			ans = true;
		}
	}
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
