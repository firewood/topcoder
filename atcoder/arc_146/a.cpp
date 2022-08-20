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

string solve(int N, std::vector<int> A) {
	string ans;
	vector<pair<int, string>> v;
	for (auto x : A) {
		string s = to_string(x);
		v.emplace_back(make_pair(int(s.length()), s));
	}
	sort(v.rbegin(), v.rend());
	vector<int> seq = { 0,1,2 };
	do {
		string y = v[seq[0]].second + v[seq[1]].second + v[seq[2]].second;
		ans = max(ans, y);
	} while (next_permutation(seq.begin(), seq.end()));
	return ans;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, A) << endl;
	return 0;
}
