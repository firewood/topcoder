#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;
typedef long long LL;

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
	RangedSUM rsum[1024];
	for (int i = 0; i < 1024; ++i) {
		rsum[i].init(1024);
	}

	int ex[100000], ey[100000], ehp[100000];

	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		cin >> ex[i] >> ey[i] >> ehp[i];
		ex[i] += 512, ey[i] += 512;
	}
	for (int i = 0; i < K; ++i) {
		int ax, ay, w, h, d;
		cin >> ax >> ay >> w >> h >> d;
		ax += 512, ay += 512;
		int ex = min(1020, ax + w);
		for (int y = ay; y <= min(1020, ay + h); ++y) {
			rsum[y].add(ax, ex, d);
		}
	}
	LL ans = 0;
	for (int i = 0; i < N; ++i) {
		ans += max(0LL, ehp[i] - rsum[ey[i]].sum(ex[i], ex[i]));
	}
	cout << ans << endl;
	return 0;
}
