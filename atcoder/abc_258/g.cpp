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
#include <bitset>

using namespace std;

typedef bitset<3000> BS;

int64_t solve(int64_t N, std::vector<std::string> A) {
	int64_t ans = 0;
	vector<BS> fwd(N), rev(N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			if (A[i][j] != '0') {
				rev[i].set(j);
			}
		}
		for (int j = i + 1; j < N; ++j) {
			if (A[i][j] != '0') {
				fwd[j].set(i);
			}
		}
	}
	for (int i = 1; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if (A[i][j] != '0') {
				ans += (fwd[i] & rev[j]).count();
			}
		}
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<std::string> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, A) << endl;
	return 0;
}
