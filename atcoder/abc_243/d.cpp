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

int64_t solve(int64_t N, int64_t X, std::string S) {
	vector<int> v;
	while (X > 0) {
		v.emplace_back(X & 1);
		X >>= 1;
	}
	reverse(v.begin(), v.end());
	for (char c : S) {
		switch (c) {
		case 'U':
			v.pop_back();
			break;
		case 'L':
			v.emplace_back(0);
			break;
		case 'R':
			v.emplace_back(1);
			break;
		}
	}
	for (int x : v) {
		X = (X << 1) | x;
	}
	return X;
}

int main() {
	int64_t N, X;
	std::string S;
	std::cin >> N >> X >> S;
	cout << solve(N, X, S) << endl;
	return 0;
}
