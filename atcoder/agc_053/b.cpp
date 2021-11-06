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

int64_t solve(int N, std::vector<int> V) {
	priority_queue<int, vector<int>, greater<>> q;
	int64_t ans = accumulate(V.begin(), V.end(), 0LL);
	for (int i = 0; i < N; ++i) {
		q.push(V[N - i - 1]);
		q.push(V[N + i]);
		ans -= q.top();
		q.pop();
	}
	return ans;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> V(2*N);
	for (int i = 0; i < 2*N; i++) {
		std::cin >> V[i];
	}
	cout << solve(N, V) << endl;
	return 0;
}
