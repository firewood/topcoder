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

bool solve(int64_t N, int64_t K, std::string S) {
	set<vector<int>> s;
	vector<int> cnt(26);
	queue<vector<int>> q;
	for (int i = 0; i < N; ++i) {
		if (i >= K) {
			cnt[S[i - K] - 'a'] -= 1;
		}
		cnt[S[i] - 'a'] += 1;
		if (i >= K - 1) {
			q.push(cnt);
		}
		if (i >= K * 2 - 1) {
			s.insert(q.front());
			q.pop();
			if (s.find(cnt) != s.end()) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	int64_t N, K;
	std::string S;
	std::cin >> N >> K >> S;
	cout << (solve(N, K, S) ? "YES" : "NO") << endl;
	return 0;
}
