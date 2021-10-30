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

struct Fraction {
	int64_t x, y;
	bool operator < (const Fraction& f) const {
		return y * f.x < f.y * x;
	}
	bool operator <= (const Fraction& f) const {
		return y * f.x <= f.y * x;
	}
};

int main() {
	int64_t N, x, y, ans = 0;
	cin >> N;
	vector<pair<Fraction, Fraction>> v;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v.emplace_back(make_pair(Fraction({ x - 1, y }), Fraction({ x, y - 1 })));
	}
	sort(v.begin(), v.end());
	Fraction prev({ 0, 0 });
	for (auto f : v) {
		if (prev <= f.second) {
			++ans;
			prev = f.first;
		}
	}
	cout << ans << endl;
	return 0;
}
