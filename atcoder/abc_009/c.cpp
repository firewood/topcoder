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

string solve(long long N, long long K, std::string S) {
	vector<int> rcnt(256);
	for (int i = 0; i < N; ++i) {
		rcnt[S[i]] += 1;
	}
	string ans;
	for (int i = 0; i < N; ++i) {
		for (char c = 'a'; c <= 'z'; ++c) {
			if (rcnt[c] > 0) {
				vector<int> rr = rcnt;
				rr[c] -= 1;
				int k = S[i] != c, diff = 0;
				for (int j = i + 1; j < N; ++j) {
					diff += --rr[S[j]] < 0;
				}
				if (k + diff <= K) {
					K -= k;
					ans += c;
					rcnt[c] -= 1;
					break;
				}
			}
		}
	}
	return ans;
}

int main() {
	int N, K;
	std::cin >> N >> K;
	std::string S;
	std::cin >> S;
	cout << solve(N, K, S) << endl;
	return 0;
}
