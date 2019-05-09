// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n, ans = 0, c;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> c;
		ans += max(0, v[i] - c);
	}
	cout << ans << endl;
	return 0;
}
