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
	reverse(S.begin(), S.end());
	return S;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<std::string> S(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
	}
	vector<string> ans = solve(N, S);
	for (size_t i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}
