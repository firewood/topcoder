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

string solve(int64_t N, int64_t K, std::string S) {
	string ans = S;
	for (int i = 0; i < N; ++i) {
		if (S[i] == 'o') {
			if (--K < 0) {
				ans[i] = 'x';
			}
		}
	}
	return ans;
}

int main() {
	int64_t N, K;
	std::string S;
	std::cin >> N >> K >> S;
	cout << solve(N, K, S) << endl;
	return 0;
}
