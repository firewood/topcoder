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

string solve(int N, std::string S) {
	vector<char> seq({ 'A', 'B', 'C' });
	char g = '1';
	do {
		vector<int> cnt(3);
		for (int i = 0; i < 3; ++i) {
			cnt[i] = int(count(S.begin() + i * N, S.begin() + (i + 1) * N, seq[i]));
		}
		cnt = vector<int>(3, *min_element(cnt.begin(), cnt.end()));
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < N && cnt[i] > 0; ++j) {
				if (S[i * N + j] == seq[i]) {
					--cnt[i];
					S[i * N + j] = g;
				}
			}
		}
		++g;
	} while (next_permutation(seq.begin(), seq.end()));
	return S;
}

int main() {
	int N;
	std::string S;
	std::cin >> N >> S;
	cout << solve(N, S) << endl;
	return 0;
}
