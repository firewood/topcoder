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

typedef long long LL;

class BIT {
	std::vector<long long> bit;
	long long size;
public:
	BIT() { }
	BIT(long long sz) { init(sz); }
	void init(long long sz) {
		bit = std::vector<long long>((size = sz) + 1);
	}
	long long sum(long long i) {
		LL s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
	void add(long long i, long long x) {
		while (i <= size) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

vector<LL> solve(int N, std::vector<int> &a) {
	vector<LL> ans(N);
	BIT bit(N);
	// inversion number
	for (int i = 0; i < N; i++) {
		ans[0] += i - bit.sum(1 + a[i]);
		bit.add(1 + a[i], 1);
	}
	for (int i = 1; i < N; i++) {
		ans[i] = ans[i - 1] - 2 * a[i - 1] + N - 1;
	}
	return ans;
}

int main() {
    int N;
	std::cin >> N;
	std::vector<int> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	for (auto ans : solve(N, a)) {
		cout << ans << endl;
	}
	return 0;
}
