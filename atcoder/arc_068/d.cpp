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
typedef pair<int, int> II;
typedef pair<int64_t, II> III;

static const int64_t INF = 1LL << 60;

int solve(int N, std::vector<int> A) {
	priority_queue<int> q;
	map<int, int> m;
	for (int i = 0; i < N; ++i) {
		m[A[i]] += 1;
	}
	for (auto kv : m) {
		int x = kv.second;
		q.emplace(x - (x - 1) / 2 * 2);
	}
	while (!q.empty() && q.top() > 1) {
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();
		q.emplace(a - 1);
		if (b > 1) {
			q.emplace(b - 1);
		}
	}
	return q.size();
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, A) << endl;
	return 0;
}
