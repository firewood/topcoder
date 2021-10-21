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

LD solve(int64_t N, std::vector<int64_t> A, std::vector<int64_t> B) {
	LD total_time = 0, total_distance = 0;
	for (int i = 0; i < N; ++i) {
		total_time += LD(A[i]) / B[i];
	}
	total_time /= 2;
	for (int i = 0; i < N; ++i) {
		LD a = min(total_time, LD(A[i]) / B[i]);
		total_time -= a;
		total_distance += a * B[i];
	}
	return total_distance;
}

int main() {
	cout.precision(20);
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> A(N), B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i] >> B[i];
	}
	cout << solve(N, A, B) << endl;
	return 0;
}
