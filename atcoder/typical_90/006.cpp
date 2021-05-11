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

string solve1(int N, int K, const string& s) {
	vector<vector<int>> count(N + 1, vector<int>(26));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 26; ++j) {
			count[i + 1][j] = count[i][j];
		}
		count[i + 1][s[i] - 'a'] += 1;
	}
	string ans;
	for (int i = 0; i < N && ans.length() < K; ++i) {
		int c = s[i] - 'a';
		int j;
		for (j = 0; j < 26; ++j) {
			if (count[N - K + ans.length() + 1][j] - count[i][j] > 0) {
				if (c == j) {
					ans += s[i];
				}
				break;
			}
		}
	}
	return ans;
}

string solve2(int N, int K, const string& s) {
	vector<vector<int>> next_pos(N + 1, vector<int>(26, 1 << 30));
	for (int i = N - 1; i >= 0; --i) {
		next_pos[i] = next_pos[i + 1];
		next_pos[i][s[i] - 'a'] = i;
	}
	int pos = 0;
	string ans;
	for (int i = 0; i < K; ++i) {
		for (int j = 0; j < 26; ++j) {
			if (next_pos[pos][j] <= N - K + i) {
				ans += char('a' + j);
				pos = next_pos[pos][j] + 1;
				break;
			}
		}
	}
	return ans;
}

int main() {
	int N, K;
	string s;
	std::cin >> N >> K >> s;
	cout << solve2(N, K, s) << endl;
	return 0;
}
