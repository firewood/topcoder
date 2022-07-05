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
	int64_t N, Q, t, x, p = 0;
	string s;
	cin >> N >> Q;
	cin >> s;
	for (int i = 0; i < Q; i++) {
		cin >> t >> x;
		if (t == 1) {
			p = (p + x) % N;
		}
		if (t == 2) {
			cout << s[(x - 1 + N - p) % N] << endl;
		}
	}
	return 0;
}
