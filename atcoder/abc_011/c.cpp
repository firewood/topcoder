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

bool solve(int N, std::vector<int> NG) {
	set<int> s, ng(NG.begin(), NG.end());
	if (ng.find(N) != ng.end()) return false;
	s.insert(N);
	for (int i = 0; i < 100; ++i) {
		set<int> next;
		for (auto x : s) {
			for (int y : {1, 2, 3}) {
				int v = x - y;
				if (ng.find(v) == ng.end()) {
					if (v == 0) {
						return true;
					}
					next.insert(v);
				}
			}
		}
		s = next;
	}
	return false;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> NG(3);
	for (int i = 0; i < 3; i++) {
		std::cin >> NG[i];
	}
	cout << (solve(N, NG) ? "YES" : "NO") << endl;
	return 0;
}
