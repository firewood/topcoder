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

vector<int> solve(int64_t N) {
	vector<int64_t> f = { 1, 2 };
	for (int i = 0; f.back() < 1e18; ++i) {
		f.emplace_back(f[f.size() - 2] + f.back());
	}
	f.pop_back();
	vector<int> ans;
	bool x = true;
	for (int i = f.size() - 1; i >= 0; --i) {
		if (N >= f[i]) {
			N -= f[i];
			ans.emplace_back(x ? 1 : 2);
		}
		ans.emplace_back(x ? 3 : 4);
		x = !x;
	}
	ans.emplace_back(x ? 3 : 4);
	return ans;
}

int64_t verify(vector<int> seq) {
	int64_t x = 0, y = 0;
	for (auto a : seq) {
		switch (a) {
		case 1:
			x += 1;
			break;
		case 2:
			y += 1;
			break;
		case 3:
			x = x + y;
			break;
		case 4:
			y = x + y;
			break;
		}
	}
	return x;
}

int main() {
	int64_t N;
	std::cin >> N;
	vector<int> ans = solve(N);
	cout << ans.size() << endl;
	for (auto t : ans) {
		cout << t << endl;
	}
	int64_t x = verify(ans);
	return 0;
}
