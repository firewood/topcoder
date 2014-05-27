// Google Code Jam 2014 R1B
// Problem A. The Repeater

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

typedef vector<string> StrVec;

int solve(void)
{
	int N = 0;

	string s;
	getline(cin, s);
	{
		stringstream ss(s);
		ss >> N;
	}

	StrVec v;
	for (int i = 0; i < N; ++i) {
		getline(cin, s);
		v.push_back(s);
	}

	int cols = 0;
	int cnt[102][102] = {};
	int ch[102] = {};
	for (int i = 0; i < N; ++i) {
		s = v[i];
		char prev = -1;
		int col = 0;
		for (char c : s) {
			if (isalpha(c)) {
				if (prev != c) {
					++col;
					if (ch[col] != 0 && ch[col] != c) {
						return -1;
					}
					ch[col] = c;
				}
				cnt[i][col] += 1;
				prev = c;
			}
		}
		if (cols > 0 && col != cols) {
			return -1;
		}
		cols = col;
	}

	int ans = 0;
	for (int c = 1; c <= cols; ++c) {
		int m = 1 << 30;
		for (int j = 1; j <= 100; ++j) {
			int sum = 0;
			for (int i = 0; i < N; ++i) {
				sum += abs(cnt[i][c] - j);
			}
			m = min(m, sum);
		}
		ans += m;
	}

	return ans;
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	if (T <= 0) return 0;

	for (int t = 1; t <= T; ++t) {
		int ans = solve();
		printf("Case #%d: ", t);
		if (ans < 0) {
			printf("Fegla Won\n");
		} else {
			printf("%d\n", ans);
		}
	}

	return 0;
}

