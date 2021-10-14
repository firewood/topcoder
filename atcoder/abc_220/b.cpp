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

int64_t g(int64_t K, string x) {
#if 1
	return stoll(x, nullptr, K);
#else
	int64_t y = 0;
	for (auto c : x) {
		y *= K;
		y += c - '0';
	}
	return y;
#endif
}

int64_t solve(int64_t K, string A, string B) {
	int64_t ans = g(K, A) * g(K, B);
	return ans;
}

int main() {
#if DEBUG || _DEBUG
	freopen("in.txt", "r", stdin);
	//	freopen("in_1.txt", "r", stdin);
#endif
	int64_t K;
	string A, B;
	std::cin >> K >> A >> B;
	cout << solve(K, A, B) << endl;
	return 0;
}
