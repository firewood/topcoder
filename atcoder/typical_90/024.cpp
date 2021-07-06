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

bool solve(int64_t N, int64_t K, std::vector<int64_t> A, std::vector<int64_t> B) {
    int64_t sum = 0;
    for (int i = 0; i < N; i++) {
        sum += abs(A[i] - B[i]);
    }
    return sum <= K && (sum - K) % 2 == 0;
}

int main() {
#if DEBUG || _DEBUG
	freopen("in.txt", "r", stdin);
//	freopen("in_1.txt", "r", stdin);
#endif
	int64_t N, K;
	std::cin >> N >> K;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	std::vector<int64_t> B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> B[i];
	}
	cout << (solve(N, K, std::move(A), std::move(B)) ? "Yes" : "No") << endl;
	return 0;
}
