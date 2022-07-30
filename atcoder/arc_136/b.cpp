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

using namespace std;

typedef long double LD;
typedef pair<int64_t, int64_t> II;
typedef pair<int64_t, II> III;

static const int64_t INF = 1LL << 60;

class BIT {
	std::vector<int64_t> bit;
	int64_t size;
public:
	BIT() { }
	BIT(int64_t sz) { init(sz); }
	void init(int64_t sz) {
		bit = std::vector<int64_t>((size = sz) + 1);
	}
	int64_t sum(int64_t i) {
		int64_t s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
	int64_t sum(int64_t left, int64_t right) {
		return sum(right) - sum(left - 1);
	}
	void add(int64_t i, int64_t x) {
		while (i <= size) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

bool solve(int N, std::vector<int> A, std::vector<int> B) {
	map<int, int> ma, mb;
	for (auto a : A) {
		ma[a] += 1;
	}
	for (auto b : B) {
		mb[b] += 1;
	}
	if (ma != mb) {
		return false;
	}
	for (auto kv : ma) {
		if (kv.second >= 2) {
			return true;
		}
	}
	auto calc_inversion_number = [&](const vector<int>& a) {
		BIT bit(5000);
		int64_t c = 0;
		for (int i = 0; i < a.size(); ++i) {
			c += bit.sum(a[i], 5000);
			bit.add(a[i], 1);
		}
		return c;
	};
	return (calc_inversion_number(A) % 2) == (calc_inversion_number(B) % 2);
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	std::vector<int> B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> B[i];
	}
	cout << (solve(N, A, B) ? "Yes" : "No") << endl;
	return 0;
}
