// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	vector<int> t;
	int ans = 0;
	for (int i = 0; i < 5; ++i) {
		int a, b;
		cin >> a;
		b = a % 10;
		ans += a - b;
		if (b) {
			t.push_back(b);
			ans += 10;
		}
	}
	if (!t.empty()) {
		sort(t.begin(), t.end());
		ans -= 10 - t.front();
	}
	cout << ans << endl;
	return 0;
}
