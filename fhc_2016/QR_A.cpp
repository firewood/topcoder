//
// Facebook Hacker Cup 2016 Qualification Round
// A. Boomerang Constellations
//

#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

typedef map<int, int> IntMap;

int main(int argc, char *argv[])
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N;
		cin >> N;
		int x[2000], y[2000];
		for (int i = 0; i < N; ++i) {
			cin >> x[i] >> y[i];
		}
		IntMap m[2000];
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				int d = (x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]);
				m[i][d] += 1;
				m[j][d] += 1;
			}
		}
		int ans = 0;
		for (int i = 0; i < N; ++i) {
			for (auto it : m[i]) {
				ans += (it.second * (it.second - 1)) / 2;
			}
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
