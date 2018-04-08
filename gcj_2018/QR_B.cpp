// Google Code Jam 2018 Qualification Round
// Problem B. Trouble Sort

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int> &v) {
	vector<int> a[2];
	for (int i = 0; i != v.size(); ++i) {
		a[i % 2].push_back(v[i]);
	}
	for (int i = 0; i < 2; ++i) {
		sort(a[i].begin(), a[i].end());
	}
	vector<int> sorted = v;
	sort(sorted.begin(), sorted.end());
	for (int i = 0; i != v.size(); ++i) {
		if (sorted[i] != a[i % 2][i / 2]) {
			return i;
		}
	}
	return -1;
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		int ans = solve(v);
		if (ans < 0) {
			cout << "Case #" << t << ": OK" << endl;
		} else {
			cout << "Case #" << t << ": " << ans << endl;
		}
	}
	return 0;
}
