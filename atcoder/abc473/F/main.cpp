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
#include <atcoder/lazysegtree>

using namespace std;

const string YES = "Yes";
const string NO = "No";


struct Data {
	int count;
	Data(int c) : count(c) { }

	static Data op(const Data left, const Data right) {
		return Data(min(left.count, right.count));
	}

	static Data empty() {
		return Data(1000000000);
	}

	static Data mapping(int a, Data b) {
		return Data(a + b.count);
	}

	static int composition(int a, int b) {
		return a + b;
	}

	static int id() {
		return 0;
	}
};


vector<int> solve(int64_t N, int64_t Q, string &S, vector<int> &types, vector<int> &indices, vector<int> &extra) {
	vector<int> ans;

	vector<Data> values(N + 1, 0);
	for (int i = 0; i < N; ++i) {
		values[i + 1] = Data(values[i].count + (S[i] == 'A' ? 1 : -1));
	}
	atcoder::lazy_segtree<Data, Data::op, Data::empty, int, Data::mapping, Data::composition, Data::id> seg(values);

	for (int64_t i = 0; i < Q; ++i) {
		if (types[i] == 1) {
			int next = (S[indices[i]] == 'A' ? -1 : 1) + (extra[i] == 'A' ? 1 : -1);
			S[indices[i]] = extra[i];
			seg.apply(indices[i] + 1, N + 1, next);
		} else {
			Data a = seg.get(indices[i]);
			Data b = seg.prod(indices[i], extra[i] + 1);
			ans.emplace_back(a.count == b.count);
		}
	}
	return ans;
}

int main() {
	int64_t N, Q;
	string S;
	cin >> N;
	cin >> S;
	cin >> Q;
	vector<int> types(Q), indices(Q), extra(Q);
	for (int64_t i = 0; i < Q; ++i) {
		cin >> types[i] >> indices[i];
		--indices[i];
		if (types[i] == 1) {
			char c;
			cin >> c;
			extra[i] = c;
		} else {
			cin >> extra[i];
		}
	}
	auto answers = solve(N, Q, S, types, indices, extra);
	for (int i = 0; i < answers.size(); i++) {
		const auto ans = answers[i];
		cout << (ans ? YES : NO) << endl;
	}
}
