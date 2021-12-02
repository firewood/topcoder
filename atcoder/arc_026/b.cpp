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

string solve(int64_t N) {
	int64_t x = N != 1;
	for (int64_t i = 2; i * i <= N; ++i) {
		if ((N % i) == 0) {
			x += i;
			if (i * i != N) {
				x += N / i;
			}
		}
	}
	if (x == N) {
		return "Perfect";
	}
	return x < N ? "Deficient" : "Abundant";
}

int main() {
	int64_t N;
	std::cin >> N;
	cout << solve(N) << endl;
	return 0;
}
