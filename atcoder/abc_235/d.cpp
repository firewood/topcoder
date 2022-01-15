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

int64_t solve(int64_t a, int64_t N) {
	vector<int> memo(1000000, -1);
	vector<int> q;
	q.emplace_back(1);
	for (int i = 1; !q.empty(); ++i) {
		vector<int> nq;
		for (int x : q) {
			int64_t y = a * x;
			if (y < 1000000 && memo[y] < 0) {
				memo[y] = i;
				nq.emplace_back(int(y));
			}
			int r = x % 10;
			if (r) {
				int z = stoi(string(1, char('0' + r)) + to_string(x / 10));
				if (memo[z] < 0) {
					memo[z] = i;
					nq.emplace_back(z);
				}
			}
		}
		q = nq;
	}
	return memo[N];
}

int main() {
	int64_t a, N;
	std::cin >> a >> N;
	cout << solve(a, N) << endl;
	return 0;
}
