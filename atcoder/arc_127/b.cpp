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

set<string> solve(int64_t N, int64_t L) {
	set<string> ans;
	vector<int> v(L - 1);
	vector<vector<int>> r(L, vector<int>(3));
	for (int i = 0; i < N; ++i) {
		string x = "0";
		string y = "1";
		string z = "2";
		for (int j = 0; j < L - 1; ++j) {
			x += char('0' + ((v[j] + 1) % 3));
			y += char('0' + ((v[j] + 2) % 3));
			z += char('0' + v[j]);
		}
		ans.insert(x);
		ans.insert(y);
		ans.insert(z);
		for (int j = L - 2; j >= 0; --j) {
			v[j] += 1;
			if (v[j] < 3) {
				break;
			}
			v[j] = 0;
		}
	}
	return ans;
}

int main() {
	int64_t N, L;
	std::cin >> N >> L;
	set<string> ans = solve(N, L);
	for (auto s : ans) {
		cout << s << endl;
	}
	return 0;
}
