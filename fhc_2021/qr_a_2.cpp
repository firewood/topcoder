// Facebook Hacker Cup 2021 Qualification Round
// Problem A2: Consistency - Chapter 2

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

const int INF = 1 << 29;

int solve(string s, vector<vector<int>> dist) {
	int ans = INF;
	for (int k = 0; k < 26; ++k) {
		for (int i = 0; i < 26; ++i) {
			for (int j = 0; j < 26; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (int i = 0; i < 26; ++i) {
		int total = 0;
		for (auto ch : s) {
			total = min(INF, total + dist[ch - 'A'][i]);
		}
		ans = min(ans, total);
	}
	return ans < INF ? ans : -1;
}

int solve2(string s, vector<string> rules) {
	vector<vector<int>> dist(26, vector<int>(26, INF));
	for (int i = 0; i < 26; ++i) {
		dist[i][i] = 0;
	}
	for (auto rule : rules) {
		dist[rule[0] - 'A'][rule[1] - 'A'] = 1;
	}
	return solve(s, dist);
}

int main(int argc, char* argv[]) {
	int T, k;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		string s;
		cin >> s;
		cin >> k;
		vector<string> rules(k);
		for (int i = 0; i < k; ++i) {
			cin >> rules[i];
		}
		cout << "Case #" << t << ": " << solve2(s, rules) << endl;
	}
	return 0;
}
