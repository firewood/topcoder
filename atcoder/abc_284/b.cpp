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
	int T, N, a;
	cin >> T;
	for (int tt = 0; tt < T; ++tt) {
		int ans = 0;
		cin >> N;
		for (int i = 0; i < N; ++i) {
			cin >> a;
			ans += a % 2;
		}
		cout << ans << endl;
	}
	return 0;
}
