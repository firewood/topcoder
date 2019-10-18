// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	cout.precision(16);
	static const int COMBSZ = 128;
	LL C[COMBSZ][COMBSZ] = { 1 };
	for (int i = 1; i < COMBSZ; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
	while (true) {
		int n = -1, a, b;
		cin >> n >> a >> b;
		if (n <= 0) break;
		vector<LL> v(n);
		map<LL, int> m;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			m[v[i]] += 1;
		}
		sort(v.rbegin(), v.rend());
		double avg = accumulate(v.begin(), v.begin() + a, 0.0) / a;
		cout << avg << endl;
		LL ans = 0;
		if (v.front() == v.back()) {
			for (int i = a; i <= b; ++i) {
				ans += C[n][i];
			}
		} else {
			for (int i = a - 1; i >= 0; --i) {
				if (v[i] != v[a - 1]) {
					break;
				}
				ans = C[m[v[a - 1]]][a - i];
			}
		}
		cout << ans << endl;
	}
	return 0;
}
