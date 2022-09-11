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

string solve(int64_t N, std::string S) {
	string ans = S, r = S;
	if (S.find('p') == string::npos) {
		return S;
	}
	int pos = S.find('p');
	for (int i = 0; i < N; ++i) {
		r[i] = char(S[i] == 'p' ? 'd' : 'p');
	}
	reverse(r.begin(), r.end());
	for (int len = 1; pos + len <= N; ++len) {
		string x = S.substr(0, pos) + r.substr(N - pos - len, len) + S.substr(pos + len);
		if (x < ans) {
			ans = x;
		}
	}
	return ans;
}

int main() {
	int64_t N;
	std::string S;
	std::cin >> N >> S;
	cout << solve(N, S) << endl;
	return 0;
}
