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

// Mo's algorithm
vector<int> solve(int N, int Q, const vector<int>& A, const vector<int>& L, const vector<int>& R) {
	const int bucket_size = int(sqrt(N));
	vector<int> ans(Q), seq(Q), cnt(N);
	iota(seq.begin(), seq.end(), 0);
	sort(seq.begin(), seq.end(), [&](int lhs, int rhs) {
		int lb = L[lhs] / bucket_size, rb = L[rhs] / bucket_size;
		if (lb == rb) {
			return lb % 2 ? R[lhs] > R[rhs] : R[lhs] < R[rhs];
		} else {
			return L[lhs] < L[rhs];
		}
	});
	int pairs = 0, left = L[seq[0]], right = L[seq[0]] - 1;
	for (auto i : seq) {
		int nl = L[i], nr = R[i];
		while (nl < left) {
			pairs += (++cnt[A[--left]] % 2) == 0;
		}
		while (right < nr) {
			pairs += (++cnt[A[++right]] % 2) == 0;
		}
		while (left < nl) {
			pairs -= (--cnt[A[left++]] % 2) != 0;
		}
		while (nr < right) {
			pairs -= (--cnt[A[right--]] % 2) != 0;
		}
		ans[i] = pairs;
	}
	return ans;
}

int main() {
	int N, Q;
	cin >> N;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
		--A[i];
	}
	cin >> Q;
	std::vector<int> L(Q), R(Q);
	for (int i = 0; i < Q; ++i) {
		cin >> L[i] >> R[i];
		--L[i];
		--R[i];
	}
	vector<int> ans = solve(N, Q, A, L, R);
	for (auto x : ans) {
		cout << x << '\n';
	}
	return 0;
}
