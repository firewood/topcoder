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

string solve(int64_t N, std::vector<std::string> S) {
	string ans;
	int mx = 0;
	map<string, int> m;
	for (string s : S) {
		m[s] += 1;
		if (m[s] > mx) {
			mx = m[s];
			ans = s;
		}
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
	cout << solve(N, S) << endl;
	return 0;
}
