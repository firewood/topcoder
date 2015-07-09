#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

class BIT {
	std::vector<int> bit;
	int size;
public:
	BIT() { }
	BIT(int sz) { init(sz); }
	void init(int sz) {
		bit = std::vector<int>((size = sz) + 1);
	}
	int sum(int i) {
		int s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
	void add(int i, int x) {
		while (i <= size) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

int main(int argc, char *argv[])
{
	int N, K;
	cin >> N >> K;
	BIT bit(1000000);
	int cnt[1000001] = {};
	int tot = 0;
	for (int i = 0; i < N; ++i) {
		int W;
		cin >> W;
		if (W > 0) {
			if ((tot - bit.sum(W-1)) < K) {
				bit.add(W, 1);
				cnt[W] += 1;
				++tot;
			}
		} else {
			if (cnt[-W] > 0) {
				bit.add(-W, -1);
				cnt[-W] -= 1;
				--tot;
			}
		}
	}
	cout << tot << endl;
	return 0;
}
