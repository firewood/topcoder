// C.

#include <iostream>
#include <algorithm>
#include <functional>
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
	string s;
	getline(cin, s);
	int Q = atoi(s.c_str());
	BIT bit(262144);
	for (int i = 0; i < Q; ++i) {
		getline(cin, s);
		stringstream ss(s);
		int T, X;
		ss >> T >> X;
		if (T == 1) {
			bit.add(X, 1);
		} else {
			int low = 0, high = 200000;
			while (high - low > 1) {
				int med = (low + high) / 2;
				int x = bit.sum(med);
				if (x < X) {
					low = med;
				} else {
					high = med;
				}
			}
			cout << high << endl;
			bit.add(high, -1);
		}
	}
	return 0;
}
