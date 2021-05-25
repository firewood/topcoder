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

void solve(long long N, std::vector<long long> &A) {
	LL sum = 0, mx = 0, tot = 0;
	for (int i = 0; i < N; i++) {
		mx = max(mx, A[i]);
		sum += A[i];
		tot += sum;
		cout << (mx * (i + 1) + tot) << endl;
	}
}

int main() {
	long long N;
	std::cin >> N;
	std::vector<long long> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	solve(N, A);
	return 0;
}
