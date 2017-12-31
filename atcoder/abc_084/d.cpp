// D.

#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> gen_primes(int m) {
	vector<int> primes;
	primes.push_back(2);
	for (int i = 3; i <= m; i += 2) {
		for (int prime : primes) {
			if (i < prime * prime) {
				primes.push_back(i);
				break;
			}
			if ((i % prime) == 0) {
				break;
			}
		}
	}
	return primes;
}

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
	vector<int> primes = gen_primes(100000);
	set<int> s(primes.begin(), primes.end());
	BIT bit(100000);
	for (int i = 3; i <= 100000; i += 2) {
		if (s.find(i) != s.end() && s.find((i + 1) / 2) != s.end()) {
			bit.add(i, 1);
		}
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		int cnt = bit.sum(r) - bit.sum(l - 1);
		cout << cnt << endl;
	}
	return 0;
}
