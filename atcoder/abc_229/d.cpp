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

int solve(std::string S, int K) {
	int ans = 0, N = S.length();
	vector<int> pos;
	for (int i = 0; i < N; ++i) {
		if (S[i] == '.') {
			pos.emplace_back(i);
		}
		int top = 0;
		if (pos.size() > K) {
			top = pos[pos.size() - K - 1] + 1;
		}
		ans = max(ans, i - top + 1);
	}
	return ans;
}

int main() {
	std::string S;
	int K;
	std::cin >> S >> K;
	cout << solve(S, K) << endl;
	return 0;
}
