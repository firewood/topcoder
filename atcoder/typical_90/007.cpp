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

void solve(int N, int Q, std::vector<int64_t>& A, std::vector<int64_t>& B) {
	A.emplace_back(-1LL << 32);
	A.emplace_back(1LL << 32);
	sort(A.begin(), A.end());
	A.resize(unique(A.begin(), A.end()) - A.begin());
	for (int i = 0; i < Q; i++) {
		int pos = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
		cout << min(B[i] - A[pos - 1], A[pos] - B[i]) << endl;
	}
}

int main() {
	int N, Q;
	cin >> N;
	vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> Q;
	std::vector<int64_t> B(Q);
	for (int i = 0; i < Q; i++) {
		cin >> B[i];
	}
	solve(N, Q, A, B);
	return 0;
}
