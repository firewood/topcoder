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

string solve(int64_t N, std::vector<string> A) {
	string ans = A[0];
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int a = -1; a <= 1; ++a) {
				for (int b = -1; b <= 1; ++b) {
					if (a == 0 && b == 0) continue;
					string s;
					for (int k = 0; k < N; ++k) {
						s += A[(i + N + k * a) % N][(j + N + k * b) % N];
					}
					ans = max(ans, s);
				}
			}
		}
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<string> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, A) << endl;
	return 0;
}
