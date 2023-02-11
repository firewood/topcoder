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

vector<int> solve(int N, int M, std::vector<int> a) {
	vector<int> ans, q;
	int ai = 0;
	for (int i = 0; i < N; ++i) {
		q.emplace_back(i);
		if (ai < M && a[ai] == i) {
			++ai;
			continue;
		}
		while (!q.empty()) {
			ans.emplace_back(q.back());
			q.pop_back();
		}
	}
	return ans;
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<int> a(M);
	for (int i = 0; i < M; i++) {
		std::cin >> a[i];
		--a[i];
	}
	vector<int> ans = solve(N, M, a);
	for (size_t i = 0; i < ans.size(); ++i) {
		if (i) cout << " ";
		cout << (ans[i] + 1);
	}
	cout << endl;
	return 0;
}
