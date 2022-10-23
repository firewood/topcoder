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

bool solve(int N, int x, int y, std::vector<int> A) {
	auto check = [&](int start_index, int initial_value, int target_value) {
		set<int> s;
		s.insert(initial_value);
		for (int i = start_index; i < N; i += 2) {
			set<int> ns;
			for (int a : s) {
				ns.insert(a - A[i]);
				ns.insert(a + A[i]);
			}
			s = ns;
		}
		return s.find(target_value) != s.end();
	};
	return check(2, A[0], x) && check(1, 0, y);
}

int main() {
	int N, x, y;
	std::cin >> N >> x >> y;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << (solve(N, x, y, A) ? "Yes" : "No") << endl;
	return 0;
}
