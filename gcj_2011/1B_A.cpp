/*

Google Code Jam 2011 Round 1B

Problem A. RPI


問題
NCAA男子バスケットボールトーナメントが毎年開かれている。
350の学校のうちRPIが高い学校が推薦される。
RPIは0.25 * WP + 0.50 * OWP + 0.25 * OOWPで計算される。
WPは勝率である。
OWPは全対戦チームの、自チームとの勝負を除いた勝率の平均である。
OOWPは全対戦チームのOWPの平均である。
全チームの対戦成績から、各チームのRPIを求める。

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> StrVec;

static void solve(StrVec v) {
	int N = v.size();
	int i, j;
	int result[128][2] = {};
	int total[128] = {};
	double WP[128] = {};
	double OWP[128] = {};
	double OOWP[128] = {};
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			if (v[i][j] != '.') {
				int win = v[i][j] - '0';
				result[i][win] += 1;
			}
		}
		total[i] = result[i][0] + result[i][1];
		if (total[i] > 0) {
			WP[i] = (double)result[i][1] / (double)total[i];
		}
	}
	for (i = 0; i < N; ++i) {
		int c = 0;
		double owp = 0;
		for (j = 0; j < N; ++j) {
			if (v[j][i] != '.' && total[j] > 1) {
				++c;
				int win = v[j][i] - '0';
				owp += (double)(result[j][1] - win) / (double)(result[j][0] + result[j][1] - 1);
			}
		}
		OWP[i] = owp / (double)c;
	}
	for (i = 0; i < N; ++i) {
		int c = 0;
		double oowp = 0;
		for (j = 0; j < N; ++j) {
			if (v[j][i] != '.') {
				++c;
				oowp += OWP[j];
			}
		}
		OOWP[i] = oowp / (double)c;
	}
	for (i = 0; i < N; ++i) {
		double rpi = (WP[i] + 2.0 * OWP[i] + OOWP[i]) / 4.0;
		cout << rpi << endl;
	}
}

int main()
{
	cout.precision(16);
	int T, N;
	cin >> T;
	int t, i;
	for (t = 0; t < T; ++t) {
		cin >> N;
		StrVec v;
		for (i = 0; i < N; ++i) {
			string s;
			cin >> s;
			v.push_back(s);
		}
		cout << "Case #" << (t+1) << ":" << endl;
		solve(v);
	}

	return 0;
}

