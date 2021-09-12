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

void get_min_positions(const vector <string>& a, int& my, int& mx) {
	my = 1 << 30, mx = 1 << 30;
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < a[0].length(); ++j) {
			if (a[i][j] != '.') {
				my = min(my, i);
				mx = min(mx, j);
			}
		}
	}
}

// rotate anti-clockwise
vector <string> rotate(const vector <string>& a) {
	if (a.empty()) {
		return a;
	}
	int h = a.size(), w = a[0].length();
	vector <string> b(w, string(h, ' '));
	for (int r = 0; r < w; ++r) {
		for (int c = 0; c < h; ++c) {
			b[r][c] = a[c][w - r - 1];
		}
	}
	return b;
}

set<pair<int, int>> get_normalized_points(const vector <string>& a) {
	set<pair<int, int>> s;
	int offset_y, offset_x;
	get_min_positions(a, offset_y, offset_x);
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < a[0].length(); ++j) {
			if (a[i][j] != '.') {
				s.insert(make_pair(i - offset_y, j - offset_x));
			}
		}
	}
	return s;
}

bool solve(int N, std::vector<std::string> S, std::vector<std::string> T) {
	for (int dir = 0; dir < 4; ++dir) {
		if (get_normalized_points(S) == get_normalized_points(T)) {
			return true;
		}
		T = rotate(T);
	}
	return false;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<std::string> S(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
	}
	std::vector<std::string> T(N);
	for (int i = 0; i < N; i++) {
		std::cin >> T[i];
	}
	cout << (solve(N, S, T) ? "Yes" : "No") << endl;
	return 0;
}
