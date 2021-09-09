// Facebook Hacker Cup 2021 Qualification Round
// Problem B: Xs and Os

#include <iostream>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

pair<int, int> solve(int N, vector<string> b) {
	int mc = N;
	set<pair<int, int>> s;
retry:
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		int cnt = 0, x = 0;
		for (int j = 0; j < N; ++j) {
			if (b[i][j] == 'O') {
				cnt = N + 1;
				break;
			}
			if (b[i][j] != 'X') {
				++cnt;
				x = j;
			}
		}
		if (cnt < mc) {
			mc = cnt;
			goto retry;
		}
		if (cnt == mc) {
			++ans;
			if (mc == 1) {
				s.insert(make_pair(i, x));
			}
		}
	}
	for (int j = 0; j < N; ++j) {
		int cnt = 0, y = 0;
		for (int i = 0; i < N; ++i) {
			if (b[i][j] == 'O') {
				cnt = N + 1;
				break;
			}
			if (b[i][j] != 'X') {
				++cnt;
				y = i;
			}
		}
		if (cnt < mc) {
			mc = cnt;
			goto retry;
		}
		if (cnt == mc) {
			++ans;
			if (mc == 1) {
				s.insert(make_pair(y, j));
			}
		}
	}
	if (mc == 1) {
		ans = s.size();
	}
	return make_pair(mc, ans);
}

int main(int argc, char* argv[]) {
	int T, N;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> N;
		vector<string> b(N);
		for (int i = 0; i < N; ++i) {
			cin >> b[i];
		}
		pair<int, int> ans = solve(N, b);
		cout << "Case #" << t << ": ";
		if (ans.second <= 0) {
			cout << "Impossible";
		} else {
			cout << ans.first << " " << ans.second;
		}
		cout << endl;
	}
	return 0;
}
