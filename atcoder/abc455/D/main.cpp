#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

std::vector<int64_t> solve(int64_t N, int64_t Q, std::vector<int64_t> C, std::vector<int64_t> P) {
	std::vector<int64_t> ans(N), parent(N, -1), child(N, -1);
	for (int qi = 0; qi < Q; ++qi) {
		int c = C[qi], p = P[qi];
		int previous_parent = parent[c];
		if (previous_parent >= 0) {
			child[previous_parent] = -1;
		}
		parent[c] = p;
		child[p] = c;
	}
	for (int i = 0; i < N; ++i) {
		if (parent[i] < 0) {
			++ans[i];
			int c = child[i];
			while (c >= 0) {
				++ans[i];
				c = child[c];
			}
		}
	}
	return ans;
}

int main() {
	int64_t N, Q;
	std::cin >> N >> Q;
	std::vector<int64_t> C(Q), P(Q);
	for (int64_t i = 0; i < Q; ++i) {
		std::cin >> C[i] >> P[i];
		--C[i];
		--P[i];
	}
	auto answers = solve(N, Q, std::move(C), std::move(P));
	for (int i = 0; i < answers.size(); i++) {
		const auto ans = answers[i];
		cout << (i > 0 ? " " : "") << ans;
	}
	if (!answers.empty()) cout << endl;
}
