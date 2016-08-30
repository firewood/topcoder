// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	LL a[500][500];
	LL p, q;
	LL sr[500] = {}, sc[500] = {};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 0) {
				p = i, q = j;
			}
			sr[i] += a[i][j];
			sc[j] += a[i][j];
		}
	}
	sort(sr, sr + N);
	sort(sc, sc + N);
	LL ans = -1;
	if (sr[1] == sr[N - 1] && sc[1] == sc[N - 1] && sr[1] == sc[1]) {
		LL r = sr[1] - sr[0];
		LL c = sc[1] - sc[0];
		if (r == c && r > 0) {
			a[p][q] = r;
			LL sd[2] = {};
			for (int i = 0; i < N; ++i) {
				sd[0] += a[i][i];
				sd[1] += a[i][N - i - 1];
			}
			if (sd[0] == sd[1] && sd[0] == sr[1]) {
				ans = r;
			}
		}
	}
	if (N == 1) {
		ans = 1;
	}
	cout << ans << endl;
	return 0;
}
