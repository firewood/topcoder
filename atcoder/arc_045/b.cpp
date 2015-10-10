// B. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;
typedef vector<II> IIVec;

class BIT {
	std::vector<LL> bit;
	int size;
public:
	BIT() { }
	BIT(int sz) { init(sz); }
	void init(int sz) {
		bit.resize((size = sz) + 1);
	}
	LL sum(int i) {
		LL s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
	void add(int i, LL x) {
		if (i == 163) {
			++i;
			--i;
		}

		while (i <= size) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

class RangedSUM {
	BIT high;
	BIT low;

public:
	RangedSUM() { }
	RangedSUM(int sz) : high(sz), low(sz) { }
	void init(int sz) {
		high.init(sz);
		low.init(sz);
	}
	void add(int start, int end, LL value) {
		low.add(start, (start - 1) * -value);
		high.add(start, value);
		low.add(end + 1, end * value);
		high.add(end + 1, -value);
	}
	LL sum(int start, int end) {
		return low.sum(end) + high.sum(end) * end - low.sum(start - 1) - high.sum(start - 1) * (start - 1);
	}
};

int main(int argc, char *argv[])
{
	RangedSUM rsum(524288);
	int N, M;
	cin >> N >> M;
	IIVec r;
	for (int i = 0; i < M; ++i) {
		int st, ed;
		cin >> st >> ed;
		rsum.add(st, ed, 1);
		r.push_back(II(st, ed));
	}

	IIVec v;
	for (int i = 1; i <= N; ++i) {
		if (rsum.sum(i, i) >= 2) {
			int ed;
			for (ed = i; ed <= N; ++ed) {
				if (rsum.sum(ed, ed) < 2) {
					break;
				}
			}
			v.push_back(II(i, ed - 1));
			i = ed;
		}
	}

	vector<int> a;
	if (!v.empty()) {
		for (int i = 0; i < M; ++i) {
			int pos = lower_bound(v.begin(), v.end(), II(r[i].second, r[i].second)) - v.begin();
			if (pos > 0 && v[pos - 1].first <= r[i].first && v[pos - 1].second >= r[i].second ||
					pos < v.size() && v[pos].first <= r[i].first && v[pos].second >= r[i].second) {
				a.push_back(i + 1);
			}
		}
	}
	cout << a.size() << endl;
	for (int i : a) {
		cout << i << endl;
	}

	return 0;
}
