// Google Code Jam 2017 Round 1C
// Problem B. 

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> II;
typedef vector<II> IIVec;

int solve() {
	int nac, naj;
	cin >> nac >> naj;
	IIVec ac, aj;
	for (int i = 0; i < nac; ++i) {
		int c, d;
		cin >> c >> d;
		ac.push_back(II(c, d));
	}
	for (int i = 0; i < naj; ++i) {
		int c, d;
		cin >> c >> d;
		aj.push_back(II(c, d));
	}
	sort(ac.begin(), ac.end());
	sort(aj.begin(), aj.end());
	if (nac + naj <= 0) {
		return 2;
	}
	if (nac == 0 || naj == 0) {
		if (nac == 0) {
			nac = naj;
			ac = aj;
		}
		if (ac[0].first >= 720 || ac[nac-1].second <= 720) {
			return 2;
		}
		if (nac == 1) {
			return 3;
		}
		//2
		if (ac[nac - 1].second <= ac[0].first + 720) {
			return 3;
		}
		int tot = ac[0].second - ac[0].first + ac[1].second - ac[1].first;
		int a = ac[0].first;
		if (tot + a <= 720) {
			tot += a;
			a = 0;
		}
		int b = 1440 - ac[1].second;
		if (tot + b <= 720) {
			tot += b;
			b = 0;
		}
		return 3 + (a != 0) + (b != 0);
	}
	// 1,1
	if (ac[0].first > aj[0].first) {
		swap(ac, aj);
	}
	if (ac[0].second <= 720 && aj[0].first >= 720) {
		return 2;
	}

	return 3;
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int ans = solve();
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
