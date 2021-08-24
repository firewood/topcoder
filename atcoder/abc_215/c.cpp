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

string solve(std::string S, int64_t K) {
	vector<string> v;
	vector<int> seq(S.length());
	iota(seq.begin(), seq.end(), 0);
	do {
		string x;
		for (int i = 0; i < S.length(); ++i) {
			x += char(S[seq[i]]);
		}
		v.push_back(x);
	} while (next_permutation(seq.begin(), seq.end()));
	sort(v.begin(), v.end());
	unique(v.begin(), v.end());		// needless to resize
	return v[K - 1];
}

int main() {
	std::string S;
	int64_t K;
	std::cin >> S >> K;
	cout << solve(S, K) << endl;
	return 0;
}
