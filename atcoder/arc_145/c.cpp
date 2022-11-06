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
#include <atcoder/modint>

using namespace std;

using mint = atcoder::modint998244353;

mint factorial(int N) {
	mint r = 1;
	for (int i = 2; i <= N; ++i) {
		r *= i;
	}
	return r;
}

mint calc_catalan_number(int N) {
	return factorial(N * 2) / factorial(N) / factorial(N + 1);
}

mint solve(int64_t N) {
	return factorial(N) * mint(2).pow(N) * calc_catalan_number(N);
}

int main() {
	int64_t N;
	std::cin >> N;
	cout << solve(N).val() << endl;
	return 0;
}
