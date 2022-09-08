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

typedef pair<int64_t, int64_t> II;

vector<II> solve(int64_t N, std::vector<int> P) {
	vector<II> ans;
	for (int i = 0; i < N; ++i) {
		if ((P[i] % 2) != (i % 2)) {
			for (int j = i + 1; j < N; j += 2) {
				if ((P[j] % 2) != (j % 2)) {
					while (j - 1 > i) {
						j -= 2;
						swap(P[j], P[j + 2]);
						ans.emplace_back(II(1, j));
					}
					break;
				}
			}
			swap(P[i], P[i + 1]);
			ans.emplace_back(II(0, i));
		}
	}
	bool f = true;
	while (f) {
		f = false;
		for (int i = 0; i < N - 2; ++i) {
			if (P[i] > P[i + 2]) {
				f = true;
				swap(P[i], P[i + 2]);
				ans.emplace_back(II(1, i));
			}
		}
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int> P(N);
	for (int i = 0; i < N; i++) {
		std::cin >> P[i];
		--P[i];
	}
	vector<II> ans = solve(N, P);
	cout << ans.size() << endl;
	for (size_t i = 0; i < ans.size(); ++i) {
		cout << (ans[i].first ? "B" : "A") << " " << (ans[i].second + 1) << endl;
	}
	return 0;
}
