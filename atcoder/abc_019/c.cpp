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
	set<int> s;
	for (int i = 0; i < N; ++i) {
		int x = a[i];
		while ((x % 2) == 0) {
			x /= 2;
		}
		s.insert(x);
	}
	return s.size();
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
