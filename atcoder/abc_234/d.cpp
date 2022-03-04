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

vector<int> solve(int N, int K, std::vector<int> P) {
	vector<int> ans;
	priority_queue<int, vector<int>, greater<>> q;
	for (int i = 0; i < N; ++i) {
		q.emplace(P[i]);
		if (q.size() > K) {
			q.pop();
		}
		if (i >= K - 1) {
			ans.emplace_back(q.top());
		}
	}
	return ans;
}

int main() {
	int N, K;
	std::cin >> N >> K;
	std::vector<int> P(N);
	for (int i = 0; i < N; i++) {
		std::cin >> P[i];
	}
	vector<int> ans = solve(N, K, P);
	for (auto x : ans) {
		cout << x << endl;
	}
	return 0;
}
