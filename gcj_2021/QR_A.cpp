// Google Code Jam 2021 Qualification Round
// Problem A. Reversort (7pts)

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solve(int n, vector<int> a) {
	int ans = 0;
	for (int i = 1; i <= n - 1; ++i) {
		int pos = find(a.begin(), a.end(), i) - a.begin() + 1;
		reverse(a.begin() + i - 1, a.begin() + pos);
		ans += pos - (i - 1);
	}
	return ans;
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		int ans = solve(n, a);
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
