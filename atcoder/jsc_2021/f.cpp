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
		while (i <= size) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

vector<int64_t> solve(int64_t N, int64_t M, int64_t Q, std::vector<int64_t> T, std::vector<int64_t> X, std::vector<int64_t> Y) {
	vector<int64_t> ans;
	set<int64_t> s(Y.begin(), Y.end());
	map<int64_t, int64_t> m;
	int64_t seq = 0;
	for (auto x : s) {
		m[x] = ++seq;
	}
	map<int64_t, int64_t> mh, mv;
	BIT cnt_h(Q), sum_h(Q), cnt_v(Q), sum_v(Q);
	int64_t sum = 0;
	for (int i = 0; i < Q; ++i) {
		switch (T[i]) {
		case 1:
			if (mh.find(X[i]) != mh.end()) {
				int64_t value = mh[X[i]];
				int64_t higher_cnt = cnt_v.sum(Q) - cnt_v.sum(m[value] - 1);
				sum -= value * (M - higher_cnt);
				sum += sum_v.sum(m[value] - 1);
				cnt_h.add(m[value], -1);
				sum_h.add(m[value], -value);
			}
			{
				int64_t higher_cnt = cnt_v.sum(Q) - cnt_v.sum(m[Y[i]] - 1);
				sum += Y[i] * (M - higher_cnt);
				sum -= sum_v.sum(m[Y[i]] - 1);
				mh[X[i]] = Y[i];
				cnt_h.add(m[Y[i]], 1);
				sum_h.add(m[Y[i]], Y[i]);
			}
			break;
		case 2:
			if (mv.find(X[i]) != mv.end()) {
				int64_t value = mv[X[i]];
				int64_t higher_cnt = cnt_h.sum(Q) - cnt_h.sum(m[value] - 1);
				sum -= value * (N - higher_cnt);
				sum += sum_h.sum(m[value] - 1);
				cnt_v.add(m[value], -1);
				sum_v.add(m[value], -value);
			}
			{
				int64_t higher_cnt = cnt_h.sum(Q) - cnt_h.sum(m[Y[i]] - 1);
				sum += Y[i] * (N - higher_cnt);
				sum -= sum_h.sum(m[Y[i]] - 1);
				mv[X[i]] = Y[i];
				cnt_v.add(m[Y[i]], 1);
				sum_v.add(m[Y[i]], Y[i]);
			}
			break;
		}
		ans.emplace_back(sum);
	}
	return ans;
}

int main() {
	int64_t N, M, Q;
	std::cin >> N >> M >> Q;
	std::vector<int64_t> T(Q), X(Q), Y(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> T[i] >> X[i] >> Y[i];
	}
	vector<int64_t> ans = solve(N, M, Q, T, X, Y);
	for (size_t i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}
