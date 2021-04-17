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

typedef pair<int, int> II;

bool is_palindrome(const vector<int>& v) {
	for (int i = 0; i < v.size() / 2; ++i) {
		if (v[i] != v[v.size() - i - 1]) {
			return false;
		}
	}
	return true;
}

int solve(int K, int level, vector<vector<II>> hist) {
	if (hist.empty()) {
		return K == 0 ? 0 : -1;
	}
	if (K == 0) {
		if (hist.size() <= 1) return -1;
		int sum = 0, ans = 1 << 30;
		vector<int> v(hist.size());
		for (int i = 0; i < (int)hist.size(); ++i) {
			sort(hist[i].rbegin(), hist[i].rend());
			v[i] = hist[i].front().second;
			sum += level - hist[i].front().first;
		}
		if (!is_palindrome(v)) {
			return sum;
		}
		for (int i = 0; i < (int)hist.size(); ++i) {
			if (hist.size() % 2 && i == hist.size() / 2) continue;
			sum += hist[i].front().first - hist[i][1].first;
			v[i] = hist[i][1].second;
			ans = min(ans, sum);
			sum -= hist[i].front().first - hist[i][1].first;
			v[i] = hist[i].front().second;
		}
		return ans;
	}
	int half_len = (int)hist.size() / 2, center = 0;
	if (hist.size() % 2) {
		sort(hist[half_len].rbegin(), hist[half_len].rend());
		center = level - hist[half_len].front().first;
	}
	for (int i = 0; i < half_len; ++i) {
		for (int j = 0; j < 26; ++j) {
			hist[i][j].first += hist[hist.size() - i - 1][j].first;
		}
	}
	hist.resize(half_len);
	int cost = solve(K - 1, level * 2, hist);
	return cost < 0 ? -1 : center + cost;
}

int solve(int K, const string& S) {
	vector<vector<II>> hist(S.length(), vector<II>(26));
	for (int i = 0; i < (int)S.length(); ++i) {
		for (int j = 0; j <	26; ++j) {
			hist[i][j].second = j;
		}
		hist[i][S[i] - 'a'].first += 1;
	}
	return solve(K, 1, hist);
}

int main() {
	int K;
	string S;
	cin >> K >> S;
	int ans = solve(K, S);
	if (ans < 0) {
		cout << "impossible" << endl;
	} else {
		cout << ans << endl;
	}
	return 0;
}
