#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstdio>

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

int main(int argc, char *argv[]) {
	int N;
	cin >> N;
	BIT bit(131072);
	int pos[131072];
	for (int i = 1; i <= N; ++i) {
		int a;
		cin >> a;
		pos[a] = i;
	}
	int ans = 0;
	for (int i = N; i >= 1; --i) {
		int s = bit.sum(pos[i]);
		if (s > 0) {
			++ans;
			bit.add(1, 1);
		} else {
			bit.add(pos[i], 1);
		}
	}
	cout << ans << endl;
	return 0;
}
