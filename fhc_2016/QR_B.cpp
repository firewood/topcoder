//
// Facebook Hacker Cup 2016 Qualification Round
// B. High Security
//

#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int N;
string b[2];

void fill(int r, int c) {
	b[r][c] = 'F';
	if (b[r ^ 1][c] == '.') {
		b[r ^ 1][c] = '-';
	}
	for (int i = c; i >= 0; --i) {
		if (b[r][i] == 'X') {
			break;
		}
		if (b[r][i] == '.') {
			b[r][i] = '-';
		}
	}
	for (int i = c; i <= N; ++i) {
		if (b[r][i] == 'X') {
			break;
		}
		if (b[r][i] == '.') {
			b[r][i] = '-';
		}
	}
}

int solve(int n, string u, string d) {
	N = n;
	b[0] = 'X' + u + 'X', b[1] = 'X' + d + 'X';
	int ans = 0;
	for (int c = 1; c <= N; ++c) {
		int p = (b[0][c - 1] != 'X') + (b[0][c + 1] != 'X');
		int q = (b[1][c - 1] != 'X') + (b[1][c + 1] != 'X');
		if (b[0][c] != 'X' && b[1][c] != 'X') {
			if (p > 0 && q == 0) {
				++ans;
				fill(0, c);
			} else if (p == 0 && q > 0) {
				++ans;
				fill(1, c);
			}
		}
	}
	for (int c = 1; c <= N; ++c) {
		for (int r = 0; r <= 1; ++r) {
			if (b[r][c] == '.') {
				while (c + 1 <= N && b[r][c + 1] == '.' && b[r ^ 1][c] != '.') {
					++c;
				}
				++ans;
				fill(r, c);
			}
		}
	}
	return ans;
}

int main(int argc, char *argv[])
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int n;
		cin >> n;
		string u, d;
		cin >> u >> d;
		int ans = solve(n, u, d);
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
