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

set<string> solve(int64_t N, int64_t K, std::vector<std::string> S) {
	return set<string>(S.begin(), S.begin() + K);
}

int main() {
	int64_t N, K;
	std::cin >> N >> K;
	std::vector<std::string> S(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
	}
	for (auto s : solve(N, K, S)) {
		cout << s << endl;
	}
	return 0;
}
