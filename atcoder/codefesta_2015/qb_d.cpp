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

struct RangeSet : map<int64_t, int64_t> {
	iterator findPreviousRange(int64_t pos) {
		auto it = lower_bound(pos);
		if (it == begin()) {
			return end();
		}
		--it;
		return it;
	}

	int64_t insertRange(int64_t start_pos, int64_t end_pos) {
		int64_t last_pos;
		// 直前の領域と結合する
		auto it = findPreviousRange(start_pos);
		if (it != end() && it->second >= start_pos) {
			end_pos = it->second + end_pos - start_pos;
			start_pos = it->first;
			erase(it);
		}
		// 次の領域が重なっていたら結合する
		it = lower_bound(start_pos);
		while (it != end() && it->first < end_pos) {
			end_pos += it->second - it->first;
			it = erase(it);
		}
		last_pos = end_pos;		// 配置できた
		// 次の領域と連続していたら結合する
		if (it != end() && it->first == end_pos) {
			end_pos += it->second - it->first;
			erase(it);
		}
		(*this)[start_pos] = end_pos;
		return last_pos;
	}
};

vector<int64_t> solve(int64_t N, std::vector<int64_t> S, std::vector<int64_t> C) {
	vector<int64_t> ans(N);
	RangeSet rs;
	for (int i = 0; i < N; ++i) {
		ans[i] = rs.insertRange(S[i], S[i] + C[i]) - 1;
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> S(N), C(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i] >> C[i];
	}
	vector<int64_t> ans = solve(N, S, C);
	for (size_t i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}
