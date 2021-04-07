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

int solve(int N, std::string S) {
	set<string> q;
	q.emplace("");
	for (int i = 0; i < (int)S.length(); ++i) {
		set<string> nq;
		for (auto s : q) {
			if (!s.empty() && s.front() == S[i]) {
				nq.emplace(s.substr(1));
			} else if (!s.empty() && s.back() == S[i]) {
				nq.emplace(s.substr(0, s.length() - 1));
			} else if (s.length() <= 10) {
				nq.emplace(S[i] + s);
				nq.emplace(s + S[i]);
			}
		}
		q = nq;
	}
	int ans = 1 << 30;
	for (auto s : q) {
		ans = min(ans, (int)s.length());
	}
	return ans;
}

int main() {
    int N;
	std::string S;
	std::cin >> N >> S;
	cout << solve(N, S) << endl;
	return 0;
}
