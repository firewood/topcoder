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

typedef pair<int64_t, vector<int>> IV;

vector<int64_t> solve(int64_t N, int64_t K, int64_t X, std::vector<int64_t> A) {
	vector<int64_t> ans;
	sort(A.rbegin(), A.rend());

	set<vector<int>> s;
	priority_queue<IV> q;

	auto enqueue = [&](int64_t sum, vector<int> &seq) {
		for (int i = 0; i < N - 1; ++i) {
			if (seq[i] > 0) {
				--seq[i];
				sum -= A[i];
				++seq[i + 1];
				sum += A[i + 1];
				if (s.find(seq) == s.end()) {
					s.insert(seq);
					q.emplace(IV(sum, seq));
				}
				--seq[i + 1];
				sum -= A[i + 1];
				++seq[i];
				sum += A[i];
			}
		}
	};

	{
		vector<int> seq(N);
		seq[0] = int(K);
		q.emplace(IV(A[0] * K, seq));
	}
	for (int i = 0; i < X; ++i) {
		int64_t sum = q.top().first;
		vector<int> seq = q.top().second;
		q.pop();
		ans.emplace_back(sum);
		enqueue(sum, seq);
	}

	return ans;
}

int main() {
	{
		int64_t N, K, X;
		std::cin >> N >> K >> X;
		std::vector<int64_t> A(N);
		for (int i = 0; i < N; i++) {
			std::cin >> A[i];
		}
		vector<int64_t> ans = solve(N, K, X, A);
		for (auto x : ans) {
			cout << x << endl;
		}
	}
	return 0;
}
