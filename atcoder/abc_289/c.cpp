#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int N, M, C, a, flags, ans = 0;
	cin >> N >> M;
	vector<int> v;
	for (int i = 0; i < M; ++i) {
		cin >> C;
		flags = 0;
		for (int i = 0; i < C; ++i) {
			cin >> a;
			flags |= (1 << (a - 1));
		}
		v.emplace_back(flags);
	}
	int mx = (1 << N) - 1;
	for (int b = 1; b < (1 << M); ++b) {
		flags = 0;
		for (int i = 0; i < M; ++i) {
			if (b & (1 << i)) {
				flags |= v[i];
			}
		}
		ans += flags == mx;
	}
	cout << ans << endl;
	return 0;
}
