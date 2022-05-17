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

int solve(int N, int K, std::string S) {
	for (int i = 1; i < N; ++i) {
		if ((N % i) == 0) {
			int sum = 0;
			for (int j = 0; j < i; ++j) {
				vector<int> cnt(26);
				for (int k = 0; k < N; k += i) {
					cnt[S[j + k] - 'a'] += 1;
				}
				sum += N / i - *max_element(cnt.begin(), cnt.end());
			}
			if (sum <= K) {
				return i;
			}
		}
	}
	return N;
}

int main() {
	int N, K;
	std::string S;
	std::cin >> N >> K >> S;
	cout << solve(N, K, S) << endl;
	return 0;
}
