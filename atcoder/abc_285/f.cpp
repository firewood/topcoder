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
#include <atcoder/fenwicktree>

using namespace std;

struct CharSet {
	vector<int> cnt, values;
	vector<atcoder::fenwick_tree<int>> bits;

	CharSet(int N) : cnt(26), values(N, -1), bits(26, atcoder::fenwick_tree<int>(N)) { }

	void update(int pos, int value) {
		if (values[pos] != value) {
			if (values[pos] >= 0) {
				cnt[values[pos]] -= 1;
				bits[values[pos]].add(pos, -1);
			}
			cnt[value] += 1;
			values[pos] = value;
			bits[value].add(pos, 1);
		}
	}

	bool is_include(int st, int ed) {
		int pos = st, prev_value = -1;
		while (pos < ed) {
			int value = values[pos];
			if (value < prev_value) return false;
			int c = bits[value].sum(pos, ed);
			if (cnt[value] < c || bits[value].sum(pos, pos + c) != c) return false;
			if (st < pos && (pos + c) < ed && cnt[value] != c) return false;
			pos += c;
			prev_value = value;
		}
		return true;
	}
};

int main() {
	int N, Q, type, a, b;
	string s;
	cin >> N;
	cin >> s;

	CharSet cs(N);
	cs.cnt = vector<int>(26);
	for (int i = 0; i < N; ++i) {
		cs.update(i, s[i] - 'a');
	}

	cin >> Q;
	for (int tt = 0; tt < Q; ++tt) {
		cin >> type >> a;
		if (type == 1) {
			cin >> s;
			cs.update(a - 1, s[0] - 'a');
		}
		if (type == 2) {
			cin >> b;
			bool ans = cs.is_include(a - 1, b);
			cout << (ans ? "Yes" : "No") << endl;
		}
	}
	return 0;
}
