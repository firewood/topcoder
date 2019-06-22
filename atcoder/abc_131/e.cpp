// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> II;

int main(int argc, char *argv[]) {
	int n, k;
	cin >> n >> k;
	vector<II> v;
	for (int j = 1; j < n; ++j) {
		v.push_back({ 1, j + 1 });
	}
	int m = ((n - 1) * (n - 2)) / 2;
	int r = m - k;
	if (r < 0) {
		cout << -1 << endl;
	} else {
		for (int i = 1; i < n; ++i) {
			for (int j = i + 1; j < n && r > 0; ++j) {
				--r;
				v.push_back({ i + 1, j + 1 });
			}
		}
		cout << v.size() << endl;
		for (auto kv : v) {
			cout << kv.first << " " << kv.second << endl;
		}
	}
	return 0;
}
