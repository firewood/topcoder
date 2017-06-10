#include <iostream>
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

int main(int argc, char *argv[]) {
	int n, k, c = 0;
	cin >> n >> k;
	BIT b(200001);
	int d[200001];
	for (int i = 1; i <= n; ++i) {
		cin >> d[i];
	}
	for (int i = n; i > 0; --i) {
		c += b.sum(d[i]);
		b.add(d[i], 1);
	}
	bool ans = c <= k && ((k - c) % 2) == 0;
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
