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

vector<string> solve(int64_t N, std::vector<std::string> S) {
	vector<string> ans;
	map<string, int> m;
	for (auto s : S) {
		int cnt = m[s];
		m[s] += 1;
		if (cnt > 0) {
			s += "(" + to_string(cnt) + ")";
		}
		ans.emplace_back(s);
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<std::string> S(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
	}
	vector<string> ans = solve(N, S);
	for (auto s : ans) {
		cout << s << endl;
	}
	return 0;
}
