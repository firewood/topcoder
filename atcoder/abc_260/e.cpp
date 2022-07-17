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

class BIT {
	std::vector<int64_t> bit;
	int64_t size;
public:
	BIT() { }
	BIT(int64_t sz) { init(sz); }
	void init(int64_t sz) {
		bit = std::vector<int64_t>((size = sz) + 1);
	}
	int64_t sum(int64_t i) {
		int64_t s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
	void add(int64_t i, int64_t x) {
		if (i < 1) return;
		while (i <= size) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

vector<int64_t> solve(int N, int M, std::vector<int> A, std::vector<int> B) {
	vector<set<int>> sa(M + 1), sb(M + 1);
	for (int i = 0; i < N; ++i) {
		sa[A[i]].insert(i);
		sb[B[i]].insert(i);
	}

	BIT bit(M * 2 + 2);
	int right = *max_element(A.begin(), A.end());
	for (int i = 1; i <= M; ++i) {
		int min_len = right - i + 1;
		bit.add(min_len, 1);
		bit.add(M - i + 2, -1);
		for (auto x : sa[i]) {
			right = max(right, B[x]);
		}
		if (!sb[i].empty() || right <= i) {
			break;
		}
	}

	vector<int64_t> ans;
	for (int i = 1; i <= M; ++i) {
		ans.emplace_back(bit.sum(i));
	}
	return ans;
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> A(N), B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i] >> B[i];
	}
	vector<int64_t> ans = solve(N, M, A, B);
	for (size_t i = 0; i < M; ++i) {
		if (i) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
