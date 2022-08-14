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
	void add(int64_t i, int64_t x) {
		while (i <= size) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

int solve(std::string S) {
	int ans = 0;
	string a = "atcoder";
	vector<int> v;
	for (char ch : S) {
		v.emplace_back(int(a.find(ch)));
	}
	BIT bit(10);
	for (int i = 0; i < v.size(); i++) {
		ans += i - bit.sum(1 + v[i]);
		bit.add(1 + v[i], 1);
	}
	return ans;
}

int main() {
	std::string S;
	std::cin >> S;
	cout << solve(S) << endl;
	return 0;
}
