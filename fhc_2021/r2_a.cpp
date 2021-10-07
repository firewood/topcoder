// Facebook Hacker Cup 2021 Round 2
// Problem A

#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int solve(int N, int M, vector<int> s, vector<vector<int>> p) {
	int ans = 0, ar = M;
	map<int, int> a, b;
	for (int i = 0; i < M; ++i) {
		a[s[i]] += 1;
	}
	for (int i = 0; i < N; ++i) {
		map<int, int> na, nb;
		int au = 0, qsz = 0;
		for (int j = 0; j < M; ++j) {
			int c = p[i][j];
			if (b.find(c) != b.end() && b[c] > 0) {
				b[c] -= 1;
				nb[c] += 1;
			}  else if (a.find(c) != a.end() && a[c] > 0) {
				++au;
				a[c] -= 1;
				na[c] += 1;
			} else {
				nb[c] += 1;
				++qsz;
			}
		}
		int x = ar - au;
		ans += qsz - x;
		ar -= x;
		a = na;
		b = nb;
	}
	return ans;
}

int main(int argc, char* argv[]) {
	int T, N, M;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> N >> M;
		vector<int> s(M);
		vector<vector<int>> p(N, vector<int>(M));
		for (int i = 0; i < M; ++i) {
			cin >> s[i];
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cin >> p[i][j];
			}
		}
		cout << "Case #" << t << ": " << solve(N, M, s, p) << endl;
	}
	return 0;
}
