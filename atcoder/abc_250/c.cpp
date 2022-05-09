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

vector<int> solve(int N, int Q, std::vector<int> x) {
	vector<int> ans(N);
	iota(ans.begin(), ans.end(), 0);
	vector<int> pos = ans;
	for (int i = 0; i < Q; ++i) {
		int p = pos[x[i]], q = p == N - 1 ? p - 1 : p + 1;
		swap(ans[p], ans[q]);
		pos[ans[p]] = p;
		pos[ans[q]] = q;
	}
	return ans;
}

int main() {
	int N, Q;
	std::cin >> N >> Q;
	std::vector<int> x(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> x[i];
		--x[i];
	}
	vector<int> ans = solve(N, Q, x);
	for (size_t i = 0; i < ans.size(); ++i) {
		if (i) cout << " ";
		cout << ans[i] + 1;
	}
	cout << endl;
	return 0;
}
