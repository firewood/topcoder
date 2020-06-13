// C.

#include <iostream>
#include <sstream>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>

using namespace std;

typedef long long LL;

struct BIT {
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

int main(int argc, char* argv[]) {
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	k = min(k, 50);

	BIT bit(n + 2);
	bit.add(1, a[0]);
	for (int i = 1; i < n; ++i) {
		bit.add(i + 1, -a[i - 1] + a[i]);
	}
	for (int i = 0; i < k; ++i) {
		//for (int i = 0; i < min(n, 20); ++i) {
		//	printf(" %3d", bit.sum(i + 1));
		//}
		//cout << endl;

		BIT next(n + 2);
		for (int j = 0; j < n; ++j) {
			int s = bit.sum(j + 1);
			int left = max(1, j + 1 - s);
			int right = min(n + 1, j + 2 + s);
			next.add(left, 1);
			next.add(right, -1);
		}
		bit = next;
	}

	for (int i = 0; i < n; ++i) {
		printf(" %d", bit.sum(i + 1));
	}
	cout << endl;
	return 0;
}
