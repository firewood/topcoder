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

typedef long double LD;
typedef pair<int, int> II;
const LD EPS = 1e-8;

bool solve(int N, vector<int> a, vector<int> b, vector<int> c, vector<int> d) {
	if (N <= 1) return true;
	LD dx = a[1] - a[0], dy = b[1] - b[0], r = sqrtl(dx * dx + dy * dy), deg = atan2l(dy, dx);
	set<II> s;
	for (int i = 0; i < N; ++i) {
		s.insert(II(a[i] - a[0], b[i] - b[0]));
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i == j) continue;
			LD dx2 = c[j] - c[i], dy2 = d[j] - d[i], r2 = sqrtl(dx2 * dx2 + dy2 * dy2), offset = atan2l(dy2, dx2) - deg;
			if (fabsl(r2 - r) > EPS) continue;
			set<II> s2;
			for (int k = 0; k < N; ++k) {
				LD dx3 = c[k] - c[i], dy3 = d[k] - d[i], r3 = sqrtl(dx3 * dx3 + dy3 * dy3), deg3 = atan2l(dy3, dx3) - offset;
				LD x = cosl(deg3) * r3, y = sinl(deg3) * r3;
				int xi = round(x), yi = round(y);
				if (fabsl(x - xi) <= EPS && fabsl(y - yi) <= EPS) {
					s2.insert(II(xi, yi));
				}
			}
			if (s == s2) {
				return true;
			}
		}
	}
	return false;
}

int main() {
#if DEBUG || _DEBUG
	freopen("in.txt", "r", stdin);
	//	freopen("in_1.txt", "r", stdin);
#endif
	int N;
	cin >> N;
	vector<int> a(N), b(N), c(N), d(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i] >> b[i];
	}
	for (int i = 0; i < N; i++) {
		std::cin >> c[i] >> d[i];
	}
	cout << (solve(N, a, b, c, d) ? "Yes" : "No") << endl;
	return 0;
}
