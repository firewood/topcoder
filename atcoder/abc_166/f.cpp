// F.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> h;
vector<int> ans;

bool dfs(int d, vector<int> &r) {
	if (d == n) {
		return true;
	}
	for (int i = 0; i < (int)r.size(); ++i) {
		if ((h[d] & (1 << i)) != 0 && r[i] > 0) {
			--r[i];
			for (int j = 0; j < (int)r.size(); ++j) {
				if (i != j && (h[d] & (1 << j)) != 0) {
					ans[d] = j;
					++r[j];
					if (dfs(d + 1, r)) {
						return true;
					}
					--r[j];
				}
			}
			++r[i];
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
		vector<int> r(3);
		cin >> n >> r[0] >> r[1] >> r[2];
		if (n < 0) return 0;
		h = vector<int>(n);
		ans.resize(n);
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			for (int j = 0; j < (int)r.size(); ++j) {
				if (s.find('A' + j) != string::npos) {
					h[i] |= 1 << j;
				}
			}
		}
		if (dfs(0, r)) {
			cout << "Yes" << endl;
			for (int j = 0; j < n; ++j) {
				cout << char('A' + ans[j]) << endl;
			}
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}
