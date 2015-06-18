#include <iostream>
#include <algorithm>
#include <sstream>
#include <numeric>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	stringstream sa(s);
	int N;
	sa >> N;
	string res[6];
	for (int i = 0; i < N; ++i) {
		getline(cin, res[i]);
	}

	int ans = N;
	int m = 1 << (N * (N - 1) / 2);
	for (int b = 0; b < m; ++b) {
		int r[6][6] = {};
		int pos = 0;
		int score[6] = {};
		int f[7] = {};
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				if (res[i][j] == '-') {
					r[i][j] = ((1 << pos) & b) != 0;
					r[j][i] = r[i][j] ^ 1;
				} else {
					r[i][j] = res[i][j] == 'o';
					r[j][i] = res[j][i] == 'o';
				}
				++pos;
			}
			score[i] = accumulate(r[i], r[i] + N, 0);
			f[score[i]] += 1;
		}
		int a = 1;
		for (int i = N; i > score[0]; --i) {
			if (f[i]) {
				++a;
			}
		}
		ans = min(ans, a);
	}
	cout << ans << endl;
	return 0;
}
