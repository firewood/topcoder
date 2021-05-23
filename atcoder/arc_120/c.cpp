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
	std::vector<long long> bit;
	long long size;
public:
	BIT() { }
	BIT(long long sz) { init(sz); }
	void init(long long sz) {
		bit = std::vector<long long>((size = sz) + 1);
	}
	long long sum(long long i) {
		long long s = 0;
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

long long solve(long long N, std::vector<long long> &A, std::vector<long long> &B) {
	for (int i = 0; i < N; i++) {
		A[i] += i;
		B[i] += i;
	}
	map<int, vector<int>> mb;
	vector<int> order(N);
	for (int i = N - 1; i >= 0; --i) {
		mb[B[i]].emplace_back(i);
	}
	for (int i = 0; i < N; i++) {
		if (mb[A[i]].empty()) {
			return -1;
		}
		order[i] = mb[A[i]].back();
		mb[A[i]].pop_back();
	}
	long long ans = 0;
	BIT bit(N);
	for (int i = 0; i < N; i++) {
		ans += i - bit.sum(1 + order[i]);
		bit.add(1 + order[i], 1);
	}
	return ans;
}

int main() {
    long long N;
	std::cin >> N;
	std::vector<long long> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	std::vector<long long> B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> B[i];
	}
	cout << solve(N, A, B) << endl;
	return 0;
}
