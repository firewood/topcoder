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

bool solve(int64_t N, int64_t X, std::vector<int64_t> a, std::vector<int64_t> b) {
	bool ans = false;
	set<int> s;
	s.insert(0);
	for (int i = 0; i < N; ++i) {
		set<int> next;
		for (auto x : s) {
			for (auto y : { x + a[i], x + b[i] }) {
				if (y <= X) {
					next.insert(y);
				}
			}
		}
		s = next;
	}
	return s.find(X) != s.end();
}

int main() {
	int64_t N, X;
	std::cin >> N >> X;
	std::vector<int64_t> a(N), b(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i] >> b[i];
	}
	cout << (solve(N, X, a, b) ? "Yes" : "No") << endl;
	return 0;
}
