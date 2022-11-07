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

static const int INF = 1 << 30;

vector<int> solve(int N, std::vector<int> P) {
#if 1
	prev_permutation(P.begin(), P.end());
#else
	set<int> s;
	int prev = INF;
	for (int i = N - 1; i >= 0; --i) {
		int x = P[i];
		s.insert(x);
		if (x < prev) {
			prev = x;
		} else {
			auto it = s.lower_bound(x);
			--it;
			int y = *it;
			s.erase(it);
			P[i] = y;
			for (int j = i + 1; j < N; ++j) {
				int y = *(s.rbegin());
				P[j] = y;
				s.erase(y);
			}
			break;
		}
	}
#endif
	return P;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> P(N);
	for (int i = 0; i < N; i++) {
		std::cin >> P[i];
	}
	vector<int> ans = solve(N, P);
	for (size_t i = 0; i < ans.size(); ++i) {
		if (i) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
