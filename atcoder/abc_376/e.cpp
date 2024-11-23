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
typedef pair<int64_t, int64_t> II;
typedef pair<int64_t, II> III;

static const int64_t INF = 1LL << 60;

int main() {
	int64_t T, N, K;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int64_t ans = INF, sum = 0;
		cin >> N >> K;
		vector<int64_t> A(N), B(N);
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> B[i];
		}

		vector<II> v;
		for (int i = 0; i < N; i++) {
			v.emplace_back(II(A[i], i));
		}
		sort(v.begin(), v.end());

		priority_queue<int64_t, vector<int64_t>> q;
		for (int i = 0; i < N; ++i) {
			q.emplace(B[v[i].second]);
			sum += B[v[i].second];
			if (q.size() > K) {
				sum -= q.top();
				q.pop();
			}
			if (q.size() >= K) {
				ans = min(ans, A[v[i].second] * sum);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
