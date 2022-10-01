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

int solve(int N, std::vector<int> a) {
	int ans = 0, rc = 0;
	set<int> s;
	for (int i = 0; i < N; ++i) {
		if (s.find(a[i]) == s.end()) {
			s.insert(a[i]);
		} else {
			++rc;
		}
	}
	auto sell = [&](int x) {
		if (!s.empty() && *s.rbegin() > x) {
			s.erase(*s.rbegin());
			return true;
		}
		return false;
	};
	for (int i = 1; i <= N; ++i) {
		if (s.find(i) == s.end()) {
			if (rc >= 2) {
				rc -= 2;
			} else {
				if (!sell(i)) {
					break;
				}
				if (rc >= 1) {
					--rc;
				} else if (!sell(i)) {
					break;
				}
			}
		}
		++ans;
	}
	return ans;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	cout << solve(N, a) << endl;
	return 0;
}
