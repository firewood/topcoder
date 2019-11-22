// D.

#include <iostream>
#include <sstream>
#include <algorithm>
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

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1;
		cin >> n;
		if (n <= 0) return 0;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		int left = -1, right = 1e9;
		while (right - left > 1) {
			int mid = (right + left) / 2;
			BIT bit(n * 2 + 1);
			long long sum = n + 1, cnt = 0, need = (long long)n * (n + 1) / 4 + 1;
			bit.add(sum, 1);
			for (int i = 0; i < n; ++i) {
				sum += a[i] > mid ? 1 : -1;
				cnt += bit.sum(2 * n) - bit.sum(sum);
				bit.add(sum, 1);
			}
			(cnt >= need ? right : left) = mid;
		}

		cout << right << endl;
	}
	return 0;
}
