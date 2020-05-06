// F.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
typedef long long LL;
typedef pair<int, int> II;

int n, a, b, c;
vector<int> h;
vector<int> ans;

bool dfs(int d, int a, int b, int c) {
	if (d == n) {
		return true;
	}
	if ((h[d] & 1) != 0 && a > 0) {
		if (h[d] & 2) {
			ans[d] = 1;
			if (dfs(d + 1, a - 1, b + 1, c)) {
				return true;
			}
		}
		if (h[d] & 4) {
			ans[d] = 2;
			if (dfs(d + 1, a - 1, b, c + 1)) {
				return true;
			}
		}
	}
	if ((h[d] & 2) != 0 && b > 0) {
		if (h[d] & 1) {
			ans[d] = 0;
			if (dfs(d + 1, a + 1, b - 1, c)) {
				return true;
			}
		}
		if (h[d] & 4) {
			ans[d] = 2;
			if (dfs(d + 1, a, b - 1, c + 1)) {
				return true;
			}
		}
	}
	if ((h[d] & 4) != 0 && c > 0) {
		if (h[d] & 1) {
			ans[d] = 0;
			if (dfs(d + 1, a + 1, b, c - 1)) {
				return true;
			}
		}
		if (h[d] & 4) {
			ans[d] = 1;
			if (dfs(d + 1, a, b + 1, c - 1)) {
				return true;
			}
		}
	}
	return false;
}

int main(int argc, char* argv[]) {
	cout.precision(20);
#ifdef _MSC_VER
	while (true)
#endif
	{
		n = -1;
		cin >> n >> a >> b >> c;
		if (n < 0) return 0;
		h.resize(n);
		ans.resize(n);
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			if (s == "AB") {
				h[i] = 3;
			}
			if (s == "AC") {
				h[i] = 5;
			}
			if (s == "BC") {
				h[i] = 6;
			}
		}
		if (dfs(0, a, b, c)) {
			cout << "Yes" << endl;
			for (int j = 0; j < n; ++j) {
				cout << (char('A' + ans[j])) << endl;
			}
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}
