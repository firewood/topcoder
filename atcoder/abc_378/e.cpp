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
#include <atcoder/fenwicktree>

using namespace std;

int main() {
	int64_t N, M, ans = 0, sum = 0;
	cin >> N >> M;

	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		A[i] %= M;
	}

	atcoder::fenwick_tree<int64_t> cnt(200002);
	int offset = 0;
	for (int i = 0; i < N; ++i) {
		int left = max(0, offset - A[i]);
		sum += int64_t(i + 1) * A[i];
		sum -= cnt.sum(left, offset) * M;
		sum -= cnt.sum(M - (A[i] - (offset - left)), M) * M;
		cnt.add(offset, 1);
		offset = (offset - A[i] + M) % M;
		ans += sum;
	}

	cout << ans << endl;
	return 0;
}
