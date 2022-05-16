#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

vector<int64_t> solve(int64_t W) {
	vector<int64_t> ans;
	int64_t b = 1;
	for (int i = 0; i < 3; ++i) {
		for (int j = 1; j < 100; ++j) {
			ans.emplace_back(b * j);
		}
		b *= 100;
	}
	return ans;
}

int main() {
	int64_t W;
	std::cin >> W;
	vector<int64_t> ans = solve(W);
	cout << ans.size() << endl;
	for (size_t i = 0; i < ans.size(); ++i) {
		if (i) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
