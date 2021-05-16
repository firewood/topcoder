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

int solve(long long N, std::string S, std::string T) {
	vector<int> a, b;
	for (int i = 0; i < N; ++i) {
		if (S[i] == '0') a.emplace_back(i);
		if (T[i] == '0') b.emplace_back(i);
	}
	if (a.size() != b.size()) return -1;
	int ans = 0;
	for (int i = 0; i < a.size(); ++i) {
		ans += a[i] != b[i];
	}
	return ans;
}

int main() {
    long long N;
	std::string S;
	std::string T;
	std::cin >> N >> S >> T;
	cout << solve(N, S, T) << endl;
	return 0;
}
