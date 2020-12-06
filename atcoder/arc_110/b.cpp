#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;

LL solve(long long N, std::string T) {
	if (N == 1) {
		return T[0] == '1' ? 20000000000 : 10000000000;
	}
	char v[3] = { '1','1','0' };
	auto check = [&]() {
		for (int offset = 0; offset < 3; ++offset) {
			auto check = [&]() {
				for (int i = 0; i < N; ++i) {
					if (T[i] != v[(i + offset) % 3]) {
						return false;
					}
				}
				return true;
			};
			if (check()) return offset;
		}
		return -1;
	};
	int offset = check();
	if (offset < 0) {
		return 0;
	} else {
		LL r = 30000000000 - offset - N;
		return r / 3 + 1;
	}
}

int main() {
	long long N;
	std::string T;
	std::cin >> N >> T;
	cout << solve(N, T) << endl;
	return 0;
}
